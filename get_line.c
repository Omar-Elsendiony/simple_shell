#include "main.h"

/**
 * _getline - gets line
 * @inputCmd: the command to be excutes
 * @argv: arr of str arg
 * @envp: environmental variable
 * Return: nothing void func
 */
int _getline(char **string, size_t *n, int fd)
{
    int sizeRead;
    *string = malloc(sizeof(*n));

	sizeRead = read(fd, *string, (*n));
    return (sizeRead);
}
