#include "main.h"

int exitCmd(char *argv[], char *env[])
{
	int i = 0;
	int num = 0;
	int total = 0;
	int mul = 1;

	(void)env;
	if (argv[1] == NULL)
	{
		free2dArr(argv);
		exit(EXIT_SUCCESS);
	}
	while (argv[1][i])
	{
		if (argv[1][i] >= '0' && argv[1][i] <= '9')
		{
			++i;
		}
		else
		{
			free2dArr(argv);
			exit(EXIT_FAILURE);
		}
	}
	while (i > -1)
	{
		--i;
		num = argv[1][i] - '0';
		num *= mul;
		total += num;
		mul *= 10;
	}
	free2dArr(argv);
	exit(total);
}

int envCmd(char *argv[], char *env[])
{
	int i = 0;

	(void)argv;
	for (i = 0; env[i] != NULL; i++)
	{
		write(STDOUT_FILENO, env[i], _strlen(env[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	return (1);
}
/*
int setenvCmd(char *argv[], char *env[])
{
	int i = 0;
	char **var = NULL;
	char *cat1 = NULL;
	char *cat2 = NULL;

	cat1 = _strcatheap(argv[1], "=");
	cat2 = _strcatheap(cat1, argv[2]);
	while (env[i])
	{
		++i;
	}

	var = malloc((sizeof(char *)) * (i + 2));
	var[i + 1] = NULL;
	i = 0;
	while (env[i])
	{
		var[i] = malloc(sizeof(char) * _strlen(env[i]) + 1);
		_strncpy(var[i], env[i], _strlen(env[i]) + 1);
		++i;
	}
	var[i] = malloc(sizeof(char) * _strlen(cat2) + 1);
	_strncpy(var[i], env[i], _strlen(cat2) + 1);
	free(cat1);
	free(cat2);
	environ = var;
	return (0);
}

int unsetemvCmd(char *argv[], char *env[])
{
	return (0);
}
int cdCmd(char *argv[], char *env[])
{
	return (0);
}
*/
