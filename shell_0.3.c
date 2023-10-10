#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>

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


char *CheckEXEInDir(char *token, char *exe, char *buff)
{
    int result;
    struct dirent *entry;
    DIR *dir = opendir(token);

    result = access(exe, F_OK);
    if (result == -1)
        while ((entry = readdir(dir)) != NULL)
        {
            if (entry->d_type == 4 && !_strcmp(entry->d_name, ".") && !_strcmp(entry->d_name, ".."))
                CheckEXEInDir(entry->d_name, exe, buff);
        }
    else
    {
        return (getcwd(buff, SIZE));
    }
    return (NULL);
}

char *readPath(char *path, char *delim)
{
    char *tokens;
    char buff[SIZE] = {0};

    tokens = strtok(path, delim);
    // k = 0;
    // while (tokens[k] != '\0')
    // {
    //     printf("%s\n--------------------------\n", tokens[k++]);
    // }
    while (tokens != NULL) {
        // printf(" %s\n", tokens);
        tokens = strtok(NULL, delim);
        if (CheckEXEInDir("testDir", "hllo", buff) != NULL)
        {
            printf("%s ***********", buff);
            break;
        }
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
                // printf("%s\n--------------------------\n", envir[i]);
                path = *(envir + i) + j + 1;
                break;
            }
        }
    }
    // printf("%s\n--------------------------\n", path);
    readPath(path, delim);

}
