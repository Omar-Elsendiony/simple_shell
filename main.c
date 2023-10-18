#include "main.h"

/**
 * main - the main entry point
 * @argc: num of argu
 * @argv: array of arg
 * @environ: the environmental var
 * Return: 0 on success, a state on failure
 */
int main(int argc, char *argv[], char *environ[])
{
	char *inputStr = NULL;
	char *cmd = NULL;
	size_t numOfLettGetline = 0;
	char **binPathes = NULL;
	char **arglist = NULL;
	int flag = 0;
	int i = 0,
		characters = 0; /*iterator alaways i will be used as iterator*/
	cmdType cmdBuiltin[] = {{"exit", exitCmd},
							{"env", envCmd},
							{NULL, NULL}}; /*, {"cd1", cdCmd}, {"setenv", setenvCmd}, {"unsetenv", unsetemvCmd}, {NULL, NULL}};*/
	/* omar variables */
	pid_t myPID;
	/* char BUFFER[SIZE]; */
	/* char *homePath; */

	signal(SIGQUIT, handler);
	myPID = getpid();
	binPathes = pathSlice(environ);
	/*homePath = getHomePath(environ);*/

	if (isatty(STDIN_FILENO) == 0)
	{
		characters = getline(&inputStr, &numOfLettGetline, stdin);
		fflush(stdin);
		if (characters == -1)
		{
			kill(myPID, SIGQUIT);
		}
		replaceNewLine(inputStr);
		arglist = slicing(inputStr, ' ');
		free(inputStr);

		if (arglist[0] == ((void *)(0)))
		{
			free2dArr(arglist);
			if (binPathes != NULL)
				free2dArr(binPathes);
			exit(EXIT_SUCCESS);
		}
		i = 0;
		while (cmdBuiltin[i].name)
		{
			if (_strcmp(arglist[0], cmdBuiltin[i].name) == 0)
			{
				if (binPathes != NULL)
					free2dArr(binPathes);
				cmdBuiltin[i].func(arglist, environ);
				free2dArr(arglist);
				exit(EXIT_SUCCESS);
			}
			++i;
		}
		if (arglist[0][0] == '/' || arglist[0][0] == '.')
		{
			if (access(arglist[0], F_OK) == 0)
			{
				forkExe(arglist[0], arglist, environ);
				if (binPathes != NULL)
					free2dArr(binPathes);
				exit(EXIT_SUCCESS);
			}
			else
			{
				perror("./hsh: ");
				free2dArr(arglist);
				if (binPathes != NULL)
					free2dArr(binPathes);
				exit(EXIT_FAILURE);
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
				forkExe(cmd, arglist, environ);
				if (binPathes != NULL)
					free2dArr(binPathes);
				exit(EXIT_SUCCESS);
			}
			else
			{
				perror("./hsh: ");
				free2dArr(arglist);
				if (binPathes != NULL)
					free2dArr(binPathes);
				exit(EXIT_FAILURE);
			}
		}
	}

	if (argc > 1)
	{
		i = 0;
		while (cmdBuiltin[i].name)
		{
			if (_strcmp(argv[1], cmdBuiltin[i].name) == 0)
			{
				if (binPathes != NULL)
					free2dArr(binPathes);
				cmdBuiltin[i].func(&argv[1], environ);
				exit(EXIT_SUCCESS);
			}
			++i;
		}
		if (argv[1][0] == '/' || argv[1][0] == '.')
		{
			if (access(argv[1], F_OK) == 0)
			{
				forkExe2(argv[1], &argv[1], environ);
				if (binPathes != NULL)
					free2dArr(binPathes);
				exit(EXIT_SUCCESS);
			}

			else
			{
				perror("./hsh: ");
				if (binPathes != NULL)
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

				forkExe2(cmd, &argv[1], environ);
				if (binPathes != NULL)
					free2dArr(binPathes);
				exit(EXIT_SUCCESS);
			}
			else
			{
				if (binPathes != NULL)
					free2dArr(binPathes);
				perror("./hsh: ");
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
			kill(myPID, SIGQUIT);
		}
		replaceNewLine(inputStr);
		arglist = slicing(inputStr, ' ');

		if (arglist[0] == ((void *)(0)))
			continue;
		i = 0;
		while (cmdBuiltin[i].name)
		{
			flag = 0;
			if (_strcmp(arglist[0], cmdBuiltin[i].name) == 0)
			{
				if (_strcmp(cmdBuiltin[i].name, "exit") == 0)
				{
					free(inputStr);
					if (binPathes != NULL)
						free2dArr(binPathes);
					cmdBuiltin[i].func(arglist, environ);
				}
				cmdBuiltin[i].func(arglist, environ);
				free2dArr(arglist);
				flag = 1;
				break;
			}
			++i;
		}
		if (flag == 1)
		{
			continue;
		}
		/*
		else if (_strcmp(arglist[0], "cd") == 0)
		{
			if (changeDirectory(arglist, BUFFER, homePath) == -1)
				perror(argv[0]);
			continue;
		}
*/
		if (arglist[0][0] == '/' || arglist[0][0] == '.')
		{
			if (access(arglist[0], F_OK) == 0)
			{
				forkExe(arglist[0], arglist, environ);
			}
			else
			{
				perror("./hsh: ");
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
				forkExe(cmd, arglist, environ);
			}
			else
			{
				perror("./hsh: ");
				free2dArr(arglist);
			}
		}
	}
}
