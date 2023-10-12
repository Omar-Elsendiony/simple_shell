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
	char *inputStrFullName = NULL;
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
		if (_strcmp(inputStr, "exit\n") == 0)
			_exit(EXIT_SUCCESS);
		if (inputStr[0] == '/' || inputStr[0] == '.')
		{
			i = 0;
			while (inputStr[i])
			{
				++i;
			}
			inputStr[i - 1] = '\0';
			if (access(inputStr, F_OK) == 0)
			{
				forkExe(inputStr, argv, envp);
			}
			else
			{
				write(STDOUT_FILENO, errorMsg, _strlen(errorMsg));
				continue;
			}
		}
		else
		{
			arglist = slicing(inputStr, ' ');
			i = 0;
			while (binPathes[i])
			{
				printf("%s*************\n", arglist[0]);
				inputStrFullName = _strcatheap(binPathes[i], arglist[0]);
				if (access(inputStrFullName, F_OK) == 0)
				{
					break;
				}
				else
				{
					free(inputStrFullName);
					++i;
				}
			}
			if (binPathes[i] != NULL)
			{
				forkExe(inputStrFullName, &arglist[1], envp);
			}
			else
			{
				write(STDOUT_FILENO, errorMsg, _strlen(errorMsg));
			}
		}
	}
	printf("this is outttttttttt\n");
	free(inputStr);
	free2dArr(binPathes);
}
