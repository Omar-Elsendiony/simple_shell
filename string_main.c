#include "simple_shell.h"
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
 * _strcat - concatenate two str
 * @dest: the buffer that recieves the output
 * @src: the buffer to read from
 * Return: pointer to char (dest)
 */

char *_strcat(char *dest, char *src)
{
	int i = 0;

	while (dest[i])
		++i;
	while (*src)
	{
		dest[i] = *src;
		++src;
		++i;
	}
	dest[i] = '\0';
	return (dest);
}
