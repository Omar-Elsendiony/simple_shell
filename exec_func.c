#include "main.h"

/**
 * forkExe - fork a process and exec command
 * @inputCmd: the command to be excutes
 * @argv: arr of str arg
 * @envp: environmental variable
 * Return: nothing void func
 */
void forkExe(char *inputCmd, char *argv[], char *envp[])
{
	int id = 0;
	int STATE_LOCK;

	id = fork();
	if (id < 0)
	{
		_exit(EXIT_FAILURE);
	}
	else if (id == 0)
	{

		execve(inputCmd, argv, envp);
	}
	else
	{
		wait(&STATE_LOCK);
		free(inputCmd);
		free2dArr(argv);
	}
}
