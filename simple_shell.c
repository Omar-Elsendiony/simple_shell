#include "simple_shell.h"

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
	int i = 0; /*iterator alaways i will be used as iterator*/

	if (argc > 1)
	{
		/* run in non interactive mode */
	}
	else
	{
		binPathes = pathSlice(envp);

		while (1)
		{
			printf("%s\n", binPathes[i]);
			write(STDOUT_FILENO, "$ ", 2);
			getline(&inputStr, &numOfLettGetline, stdin);
			fflush(stdin);
			if (_strcmp(inputStr, "exit") == 0)
				_exit(EXIT_SUCCESS);

			for (i = 0; binPathes[i]; ++i)
			{
				inputStrFullName = _strcatheap(binPathes[i], inputStr);
				if (access(inputStrFullName, X_OK) == 0)
				{
					forkExe(inputStrFullName, argv, envp);
				}
				else
				{
					write(STDOUT_FILENO, errorMsg, _strlen(errorMsg));
					exit(EXIT_FAILURE);
				}
			}
			free(inputStrFullName);
			free(inputStr);
		}
		/* free2dArr(binPathes);*/ /*write func to free the 2d array of strings of path*/
	}
}
