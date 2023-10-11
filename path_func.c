#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/*
 *this will be replacement for strtok in the future hope to finish it
 */

/**
 * _strncpy - copy a string to n char
 * @dest: pointer to frist buffer
 * @src: pointer to the srouce bffuer
 * @n: number of char to be copied
 * Return: pointer to the dest buffer
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; i < n; ++i)
	{
		dest[i] = src[i];
		if (src[i] == '\0')
		{
			while (i < n)
			{
				dest[i] = 0;
				++i;
			}
		}
	}
	return (dest);
}

int lett_count(char *st, char del)
{
	int i = 0;

	while (st[i] != del && st[i])
	{
		++i;
	}
	return (i);
}

char **str_sli(char *str)
{
	int i = 0;
	int z = 0;
	int j = 0;
	int numOfLett = 0;
	char **arr = NULL;

	for (i = 0; str[i]; ++i)
	{
		if (str[i] == ' ')
			++z;
	}
	++z;
	arr = malloc(sizeof(char *) * z + 1);
	arr[z] = NULL;
	i = 0;
	while (i < z)
	{
		numOfLett = lett_count(&str[j], ' ');
		arr[i] = malloc(numOfLett + 1);
		_strncpy(arr[i], &str[j], numOfLett + 1);
		j = j + numOfLett + 1;
		++i;
	}

	return (arr);
}

extern char **__environ;
int main(int argc, char **argv, char **envp)
{
	char **arr;
	int i = 0;
	int z = 0;
	char *ptr = 0;
	size_t n = 0;

	printf("$ ");
	getline(&ptr, &n, stdin);
	while (ptr[z])
	{
		if (ptr[z] == '\n')
		{
			ptr[z] = '\0';
			break;
		}
		++z;
	}
	execve(ptr, argv, __environ);
	return (0);
}
