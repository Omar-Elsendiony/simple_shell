#include "main.h"

/**
 * _strncat - returns the alphabet
 * @dest: pointer to integer
 * @src: pointer to second number
 * @n: number of chars
 * Description: The description
 * Return: void
*/
char *_strncat(char *dest, char *src, int n)
{
	int i, j;

	i = 0;
	while (dest[i] != '\0')
		i++;
	for (j = 0; src[j] != '\0' && n != 0; j++)
	{
		dest[i++] = src[j];
		n -= 1;
	}
	dest[i] = '\0';
	return (dest);
}


