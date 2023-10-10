#include "simple_shell.h"

int main(int argc, char *argv[], char *envp[])
{
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
		binPathes = pathSlice(envp); /*write the function to slice the path and return array of strings PS it will be heap mem free function will be written and other functions for word count and letters count */
		while (1)
		{
			write(stdout, "$ ", 2);
			getline(&inputStr, &numOfLettGetline, stdin);
			fflush(stdin);
			if (_strcmp(inputStr, "exit") == 0)
				_exit(EXIT_SUCCESS);
			for (binPathes[i])
			{
				inputStrFullName = _strcatheap(binPathes[i], inputStr); /*write the function theat concat 2 strings PS it will return heap mem*/
				if (file_accessable(inputStrFullName))					/*write a function to check the accessablility in every dir and the exictenc of file*/
				{
					forkEce(char *pinter, argv, argc, envp); /*write a function to fork and execute the programme*/
				}
				else
				{
					write(stdout, "error\n", _strlen("error\n")); /*the exact error msg will be written later*/
					exit(EXIT_FAILURE);
				}
				free(inputStrFullName);
				free(inputStr);
			}
		}
		free2dArr(binPathes); /*write func to free the 2d array of strings of path*/
	}
}