#include "main.h"

int lengthArgs(char **str)
{
    int length = 0;
    while (str[length] != NULL)
    {
        length++;
    }
    return (length);
}

void handler(int sig)
{
    if (sig == SIGQUIT)
    {
        _exit(EXIT_FAILURE);
    }
}

/**
 * changeDirectory - check the code
 * @arglist: The character to print
 *
 * Return: -1 on error else returns zero
 */
int changeDirectory(char **arglist, char *buffer, char *homePath)
{
    int numArgList = lengthArgs(arglist), returnVal, newLine = '\n';
    if (numArgList >= 3)
    {
        return (-1);
    }
    else if(numArgList == 1)
    {
        returnVal = chdir(homePath);
        if (returnVal == -1)
            return (-1);
    }
    else if (_strcmp(arglist[1], "-") == 0)
    {
        getcwd(buffer, SIZE);
        write(STDOUT_FILENO, buffer, _strlen(buffer));
        write(STDOUT_FILENO, &newLine, 1);
    }
    else
    {
        returnVal = chdir(arglist[1]);
        if (returnVal == -1)
            return (-1);
    }
    return (0);
}



/**
 * getHomePath - check the code
 * @envir: The character to print
 *
 * Return: pointer to path
 */
char *getHomePath(char ** envir)
{
    int i, j;
    char *comparator = "HOME", *path = NULL;

    for (i = 0; envir[i] != NULL; i++)
    {
        if (envir[i][0] == comparator[0])
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
    return (path);
}
