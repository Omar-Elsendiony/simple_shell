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
int changeDirectory(char **arglist, char *buffer)
{
    int numArgList = lengthArgs(arglist), returnVal, newLine = '\n';
    if (numArgList >= 3)
    {
        return (-1);
    }
    else if(numArgList == 1)
    {
        chdir("/");
    }
    else if (_strcmp(arglist[1], "-") == 0)
    {
        getcwd(buffer, SIZE);
        write(STDOUT_FILENO, buffer, _strlen(buffer));
        write(STDOUT_FILENO, &newLine, 1);
        return (0);
    }
    returnVal = chdir(arglist[1]);
    if (returnVal == -1)
        return (-1);
    return (0);
}
