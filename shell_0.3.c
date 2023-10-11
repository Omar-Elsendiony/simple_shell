#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include "utility.h"
#define SIZE 1000

int _strcmpUnnecessary(char *s1, char *s2, int count)
{
	int i, diff;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && count != 0)
    {
		i++;
        count--;
    }
	diff = s1[i] - s2[i];
	return (diff);
}



int _strcmp(char *s1, char *s2)
{
	int i, diff;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0')
		i++;
	diff = s1[i] - s2[i];
	return (diff);
}


char *CheckEXEInDir(char *path, char *exe, char *buff, int counter)
{
    if (counter == 0)
        return NULL;
    int result;
    struct dirent *entry;
    char passedDirectory[SIZE];
    char sentDirectory[SIZE];
    DIR *dir = opendir(path);
    if (dir == NULL)
        return (NULL);
    char *returnedPath;
    _strncpy(passedDirectory, path, SIZE);
    _strncpy(sentDirectory, path, SIZE);

    _strncat(passedDirectory , "/", SIZE);
    _strncat(sentDirectory , "/", SIZE);

    _strncat(path , "/", SIZE);
    _strncat(path , exe, SIZE);

    result = access(path, F_OK);
    if (result == -1)
        while ((entry = readdir(dir)) != NULL)
        {
            if (entry->d_type == DT_DIR && _strcmp(entry->d_name, ".") != 0 && _strcmp(entry->d_name, "..") != 0)
            {
                _strncat(sentDirectory ,entry->d_name, SIZE);
                returnedPath = CheckEXEInDir(sentDirectory, exe, buff, counter - 1);
                if (returnedPath != NULL)
                {
                    return (returnedPath);
                }
                _strncpy(sentDirectory, passedDirectory, SIZE);
            }
        }
    else
    {
        return (path);
    }
    return (NULL);
}

char *readPath(char *pathDir, char *delim, char *exe)
{
    char *tokens;
    char path[SIZE] = {0};
    char currentDir[SIZE] = {0};

    tokens = strtok(pathDir, delim);

    getcwd(currentDir, SIZE);
    _strncat(path, currentDir , SIZE);
    if (CheckEXEInDir(path, exe, path, 3) != NULL)
    {
        _strncpy(pathDir, path, SIZE);
        return (pathDir);
    }
    path[0] = 0;
    while (tokens != NULL) {
        tokens = strtok(NULL, delim);
        if (tokens == NULL || !_strcmpUnnecessary(tokens, "/mnt/", 3))
            continue;
        _strncat(path, tokens, SIZE);
        if (CheckEXEInDir(path, exe, path, 3) != NULL)
        {
            _strncpy(pathDir, path, SIZE);
            return (pathDir);
        }
        path[0] = 0;
    }
}


/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(int arc, char **argv, char ** envir)
{
    int i, j, k, childID;
    char *comparator = "PATH";
    char *path, *delim = ":", *brokenString;
    char *exe = "ls";

    if (execve(exe, argv, envir) == -1)
    {
        int parentID = getpid();
        /*
         * get environment path variable to parse it
        */
        for (i = 0; envir[i] != NULL; i++)
        {
            if (envir[i][0] == 'P')
            {
                j = 1;
                while (envir[i][j] == comparator[j] && envir[i][j] != '\0')
                {
                    j++;
                }
                if (comparator[j] == '\0')
                {
                    path = *(envir + i) + j + 1;
                    break;
                }
            }
        }

        path = readPath(path, delim, exe);
        if (path == NULL)
            perror("could not find path");
        else
        {
            fork();
            if (getpid() != parentID)
                if (execve(path, argv, envir) == -1)
                    perror("Could not execve");
        }
    }


}
