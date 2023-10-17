#include "main.h"

int exitCmd(char *argv[], char *env[])
{
	int i = 0;
	int num = 0;
	int total = 0;
	int mul = 1;

	while (argv[1][i])
	{
		if (argv[1][i] >= '0' && argv[1][i] <= '9')
		{
			++i;
		}
		else
		{
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
	exit(total);
}

int envCmd(char *argv[], char *env[])
{
}

int setenvCmd(char *argv[], char *env[])
{
}

int unsetemvCmd(char *argv[], char *env[])
{
}
int cdCmd(char *argv[], char *env[])
{
}
