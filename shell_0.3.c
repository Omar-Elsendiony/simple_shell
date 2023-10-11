#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include "utility.h"
#define SIZE 100





int _strcmp(char *s1, char *s2)
{
	int i, diff;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0')
		i++;
	diff = s1[i] - s2[i];
	return (diff);
}


char *CheckEXEInDir(char *path, char *exe, char *buff)
{
    int result;
    struct dirent *entry;
    char passedDirectory[SIZE];
    char sentDirectory[SIZE];
    DIR *dir = opendir(path);
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
            if (entry->d_type == DT_DIR && _strcmp(entry->d_name, ".") != 0 && _strcmp(entry->d_name, "..") != 0 && _strcmp(entry->d_name, ".git") != 0)
            {
                _strncat(sentDirectory ,entry->d_name, SIZE);
                returnedPath = CheckEXEInDir(sentDirectory, exe, buff);
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
    if (CheckEXEInDir(path, exe, path) != NULL)
    {
        printf("%s ***********", path);
        _strncpy(pathDir, path, SIZE);
        return (pathDir);
    }
    path[0] = 0;
    // k = 0;
    // while (tokens[k] != '\0')
    // {
    //     printf("%s\n--------------------------\n", tokens[k++]);
    // }
    while (tokens != NULL) {
        // printf(" %s\n", tokens);
        tokens = strtok(NULL, delim);
        _strncat(path, tokens, SIZE);
        if (CheckEXEInDir(path, exe, path) != NULL)
        {
            printf("%s ***********", path);
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
    int i, j, k;
    char *comparator = "PATH";
    char *path, *delim = ":", *brokenString;

    int parentID = getpid();
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
    // printf("%s\n--------------------------\n", path);
    path = readPath(path, delim, "ls");
    fork();
    if (getpid() != parentID)
        if (execve(path, argv, envir) == -1)
            perror("Could not execve");
}
