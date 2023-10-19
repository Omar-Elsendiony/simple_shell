#include "main.h"

/**
 * lett_count - count number of letters to certain delimtter
 * @str: the string
 * @del: delimeter the stop point for counting
 * Return: number of letters
 */
int lett_count(char *str, char del)
{
	int i = 0;

	while (str[i] != del && str[i])
	{
		++i;
	}
	return (i);
}

/**
 * word_count - count number of words in a str delimeted by a delimmter
 * @str: the string
 * @del: delimeter of words
 * Return: number of words
 */

int word_count(char *str, char del)
{
	int i = 0;
	int countOfWords = 0;

	while (str[i])
	{
		if (str[i] != del)
		{
			while (str[i] != del)
			{
				if (str[i + 1] != del && str[i + 1])
				{
					++i;
				}
				else
				{
					break;
				}
			}
			++countOfWords;
		}
		++i;
	}
	return (countOfWords);
}

/**
 * slicing - cut string into number of substring based on delimeter
 * @str: the string
 * @del: delimeter of strings
 * Return: array of strings
 */

char **slicing(char *str, char del)
{
	int i = 0;
	int j = 0;
	int numOfLett = 0;
	int numOfWord = 0;
	char **arr = NULL;

	numOfWord = word_count(str, del);
	arr = malloc(sizeof(char *) * (numOfWord + 1));
	arr[numOfWord] = NULL;
	while (i < numOfWord)
	{
		while (str[j] == del)
		{
			++j;
		}
		numOfLett = lett_count(&str[j], del);
		if (del == ':')
		{
			arr[i] = malloc(numOfLett + 2);
			_strncpy(arr[i], &str[j], numOfLett);
			arr[i][numOfLett] = '/';
			arr[i][numOfLett + 1] = '\0';
			j = j + numOfLett;
		}
		else
		{
			arr[i] = malloc(numOfLett + 1);
			_strncpy(arr[i], &str[j], numOfLett);
			arr[i][numOfLett] = '\0';
			j = j + numOfLett;
		}
		++i;
	}
	return (arr);
}

/**
 * pathSlice - wrap func for slicing func to pick the PATH var from env vars
 * @env: the environmental variables
 * Return: array of strings
 */
char **pathSlice(char **env)
{
	int i = 0;
	char *str = NULL;
	char **pathes = NULL;

	while (env[i])
	{
		if (_strncmp(env[i], "PATH=", 5) == 0)
		{
			str = &env[i][5];
			break;
		}
		++i;
	}
	if (env[i] == NULL)
	{
		return (NULL);
	}
	pathes = slicing(str, ':');
	return (pathes);
}

void free2dArr(char **arr)
{
	int i = 0;

	while (arr[i])
	{
		free(arr[i]);
		++i;
	}
	free(arr);
}
/*
int main()
{
	char *p = "    /bin/ls;  jlkj    ;";
	char **arg = NULL;
	int num = 0;

	num = word_count(p, ';');
	arg = slicing(p, ';');
	for (int i = 0; arg[i]; ++i)
	{
		printf("%s\n", arg[i]);
	}
	printf("number of words %d\n", num);
	return (0);
}
*/
