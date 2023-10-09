#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>

#define SIZE 100


char *CheckEXEInDir(char *token, char *exe)
{
    int result;
    struct dirent *entry;
    DIR *dir = opendir(token);

    result = access (exe, F_OK);
    while ((entry = readdir(dir)) != NULL)
    {
        printf("%d \n", entry->d_type);
    }
}

char *readPath(char *path, char *delim)
{
    char *tokens;

    tokens = strtok(path, delim);
    // k = 0;
    // while (tokens[k] != '\0')
    // {
    //     printf("%s\n--------------------------\n", tokens[k++]);
    // }
    while (tokens != NULL) {
        printf(" %s\n", tokens);
        tokens = strtok(NULL, delim);
        CheckEXEInDir("/bin", "ls");
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
    char *buff[SIZE];
    char *path, *delim = ":", *brokenString;

    getcwd(*buff, SIZE);
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
    printf("%s\n--------------------------\n", path);
    // readPath(path, delim);

    int result = access ("oe", F_OK);
    printf("%d\n", result);
}
