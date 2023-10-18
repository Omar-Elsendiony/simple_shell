#include "main.h"
/**
 * _strcmp - returns the alphabet
 * @s1: pointer to integer
 * @s2: pointer to second number
 * Description: The description
 * Return: void
 */
int _strcmp(char *s1, char *s2)
{
	int i, diff;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0')
		i++;
	diff = s1[i] - s2[i];
	return (diff);
}

/**
 * _strncmp - compare two string
 * @s1: pointer to frist string
 * @s2: pointer to second string
 * @n: n letters to be compared
 * Return: 0 if match + if s1 greater, - if s2 greater
 */

int _strncmp(char *s1, char *s2, int n)
{
	int i = 0;
	int f = 0;

	while (i < n)
	{
		f = s1[i] - s2[i];
		if (f != 0)
			return (f);
		++i;
	}
	return (f);
}

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

/**
 * _strcpy - copyt a string into buffer
 * @dest: destination buffer
 * @src: source buffer
 * Return: pointer to buffer
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (*(src + i))
	{
		*(dest + i) = *(src + i);
		++i;
	}
	*(dest + i) = *(src + i);
	return (dest);
}

/**
 * _strlen - funct to find the length of str
 * @s: pointer to frist letter of the str
 * Return: number of letters (int)
 */

int _strlen(char *s)
{
	int i = 0;

	while (*s)
	{
		++i;
		++s;
	}
	return (i);
}

/**
 * _strcatheap - concatenate two str dynamically
 * @dest: the frist str
 * @src: the sec str
 * Return: pointer to char (mallocated memory)
 */

char *_strcatheap(char *dest, char *src)
{
	int i = 0;
	char *conCatStr = NULL;

	conCatStr = malloc(_strlen(dest) + _strlen(src) + 1);
	while (dest[i])
	{
		conCatStr[i] = dest[i];
		++i;
	}
	while (*src)
	{
		conCatStr[i] = *src;
		++src;
		++i;
	}
	conCatStr[i] = '\0';
	return (conCatStr);
}

void replaceNewLine(char *str)
{
	int i = 0;

	while (str[i])
	{
		if (str[i] == '\n' && str[i + 1] == '\0')
		{
			str[i] = '\0';
		}
		else if (str[i] == '\n')
		{
			str[i] = ' ';
		}
		i = i + 1;
	}
}
