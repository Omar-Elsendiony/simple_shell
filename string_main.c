#include "main.h"
/**
 * _strcmp - compare two string
 * @s1: pointer to frist string
 * @s2: pointer to second string
 * Return: 0 if match + if s1 greater, - if s2 greater
 */

int _strcmp(char *s1, char *s2)
{
	int i = 0;
	int len;
	int f = 0;

	len = _strlen(s1) + 1;
	while (i < len)
	{
		f = s1[i] - s2[i];
		if (f != 0)
			return (f);
		++i;
	}
	return (f);
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
	if (*str == '\0' || str == NULL)
	{
		return;
	}
	while (*str != '\n')
	{
		++str;
	}
	*str = '\0';
}
