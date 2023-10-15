#include "main.h"

/**
 * main - the main entry point
 * @argc: num of argu
 * @argv: array of arg
 * @envp: the environmental var
 * Return: 0 on success, a state on failure
 */
int main(int argc, char *argv[], char *envp[])
{
	char *errorMsgNoFile = ": No such file or directory\n";
	char *errorMsgNoCmd = ": command not found\n";
	char *inputStr = NULL;
	char *cmd = NULL;
	size_t numOfLettGetline = 0;
	char **binPathes = NULL;
	char **arglist = NULL;
	char *err = NULL;
	char *finalErr = NULL;
	int i = 0, characters = 0; /*iterator alaways i will be used as iterator*/
    pid_t myPID;

    signal(SIGQUIT, handler);
    myPID = getpid();
	binPathes = pathSlice(envp);
	if (argc > 1)
	{
		if (argv[1][0] == '/' || argv[1][0] == '.')
		{
			if (access(argv[1], F_OK) == 0)
			{
				forkExe2(argv[1], &argv[1], envp);
				free2dArr(binPathes);
				exit(EXIT_SUCCESS);
			}
			else
			{
				err = _strcatheap("bash: ", argv[1]);
				finalErr = _strcatheap(err, errorMsgNoFile);
				free(err);
				write(STDOUT_FILENO, finalErr, _strlen(finalErr));
				free(finalErr);
				free2dArr(binPathes);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			i = 0;
			while (binPathes[i])
			{
				cmd = _strcatheap(binPathes[i], argv[1]);
				if (access(cmd, F_OK) == 0)
				{
					break;
				}
				else
				{
					free(cmd);
					++i;
				}
			}
			if (binPathes[i] != NULL)
			{
				forkExe2(cmd, &argv[1], envp);
				free2dArr(binPathes);
				exit(EXIT_SUCCESS);
			}
			else
			{
				err = _strcatheap("bash: ", argv[1]);
				finalErr = _strcatheap(err, errorMsgNoCmd);
				free(err);
				write(STDOUT_FILENO, finalErr, _strlen(finalErr));
				free(finalErr);
				free2dArr(binPathes);
				exit(EXIT_FAILURE);
			}
		}
	}
	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);
        fflush(stdin);
		characters = getline(&inputStr, &numOfLettGetline, stdin);
		fflush(stdin);
        if (characters == -1)
        {
            kill(myPID,SIGQUIT);
        }
		replaceNewLine(inputStr);
		arglist = slicing(inputStr, ' ');

        if (arglist[0] == ((void *)(0)))
            continue;
		if (_strcmp(arglist[0], "exit") == 0)
		{
			free(inputStr);
			free2dArr(binPathes);
			free2dArr(arglist);
			_exit(EXIT_SUCCESS);
		}

		if (arglist[0][0] == '/' || arglist[0][0] == '.')
		{
			if (access(arglist[0], F_OK) == 0)
			{
				forkExe(arglist[0], arglist, envp);
			}
			else
			{
				err = _strcatheap("bash: ", arglist[0]);
				finalErr = _strcatheap(err, errorMsgNoFile);
				free(err);
				write(STDOUT_FILENO, finalErr, _strlen(finalErr));
				free2dArr(arglist);
				free(finalErr);
				continue;
			}
		}
		else
		{
			i = 0;
			while (binPathes[i])
			{
				cmd = _strcatheap(binPathes[i], arglist[0]);
				if (access(cmd, F_OK) == 0)
				{
					break;
				}
				else
				{
					free(cmd);
					++i;
				}
			}
			if (binPathes[i] != NULL)
			{
				forkExe(cmd, arglist, envp);
			}
			else
			{
				err = _strcatheap("bash: ", arglist[0]);
				finalErr = _strcatheap(err, errorMsgNoCmd);
				free(err);
				write(STDOUT_FILENO, finalErr, _strlen(finalErr));
				free(finalErr);
				free2dArr(arglist);
			}
		}
	}
}


void handler(int sig)
{
    if (sig == SIGQUIT)
    {
        _exit(EXIT_FAILURE);
    }
}
