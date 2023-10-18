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

char *getEnvVar(char ** envir, char *envVariable)
{
    int i, j;
    char *comparator = envVariable, *path = NULL;

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


/**
 * changeDirectory - check the code
 * @arglist: The character to print
 *
 * Return: -1 on error else returns zero
 */
int changeDirectory(char **arglist, char **env)
{
    int numArgList = lengthArgs(arglist), returnVal, newLine = '\n';
    char *path = NULL, BUFFER[1024];

    getcwd(BUFFER, 1024);
    if (numArgList >= 3)
    {
        return (-1);
    }
    else if(numArgList == 1)
    {
        setenv("OLDPWD", getEnvVar(env, "PWD"), 1);
        path = getEnvVar(env, "HOME");
        returnVal = chdir(path);
        if (returnVal == -1)
            return (-1);
    }
    else if (_strcmp(arglist[1], "-") == 0)
    {
        path = getEnvVar(env, "OLDPWD");
        setenv("OLDPWD", BUFFER, 1);
        if (path == NULL)
            return (-1);
        returnVal = chdir(path);
        if (returnVal == -1)
            return (-1);
        write(STDOUT_FILENO, path, _strlen(path));
        write(STDOUT_FILENO, &newLine, 1);
    }
    else
    {
        setenv("OLDPWD", BUFFER, 1);
        returnVal = chdir(arglist[1]);
        if (returnVal == -1)
            return (-1);
    }
    setenv("PWD", BUFFER, 1);
    return (0);
}



