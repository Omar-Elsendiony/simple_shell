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
	char *errorMsg = "there is no such file of directory\n";
	char *inputStr = NULL;
	char *cmd = NULL;
	size_t numOfLettGetline = 0;
	char **binPathes = NULL;
	char **arglist = NULL;
	int i = 0; /*iterator alaways i will be used as iterator*/

	binPathes = pathSlice(envp);
	if (argc > 1)
	{
		/* run in non interactive mode */
	}
	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);
		getline(&inputStr, &numOfLettGetline, stdin);
		fflush(stdin);
		replaceNewLine(inputStr);
		arglist = slicing(inputStr, ' ');

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
				write(STDOUT_FILENO, errorMsg, _strlen(errorMsg));
				free2dArr(arglist);
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
				write(STDOUT_FILENO, errorMsg, _strlen(errorMsg));
				free2dArr(arglist);
			}
		}
	}
}
