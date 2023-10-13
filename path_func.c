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
		if (str[i] == del)
		{
			++countOfWords;
			while (str[i] == del)
			{
				if (str[i + 1] == del)
				{
					++i;
				}
				else
				{
					break;
				}
			}
		}
		++i;
	}
	++countOfWords;
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
		numOfLett = lett_count(&str[j], del);
		if (del == ':')
		{
			arr[i] = malloc(numOfLett + 2);
			_strncpy(arr[i], &str[j], numOfLett);
			arr[i][numOfLett] = '/';
			arr[i][numOfLett + 1] = '\0';
			j = j + numOfLett + 1;
			while (str[j] == del)
			{
				if (str[j + 1] == del)
				{
					++j;
				}
				else
				{
					++j;
					break;
				}
			}
		}
		else
		{
			arr[i] = malloc(numOfLett + 1);
			_strncpy(arr[i], &str[j], numOfLett);
			arr[i][numOfLett] = '\0';
			j = j + numOfLett + 1;
			while (str[j] == del)
			{
				if (str[j + 1] == del)
				{
					++j;
				}
				else
				{
					++j;
					break;
				}
			}
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
int main(int argc, char *argv[], char *env[])
{
	char *res = "hello  world\n";
	char **sl = slicing(res, ' ');
	int i = 0;

	while (sl[i])
	{
		printf("%s\n", sl[i]);
		++i;
	}
	return (0);
}
*/
