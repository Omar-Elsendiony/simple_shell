#include "main.h"


/**
 * _strlen - returns the alphabet
 * @s: pointer to integer
 * Description: The description
 * Return: int
*/
int _strlen(char *s)
{
	int i, length;

	i = 0;
	length = 0;
	while (s[i] != '\0')
	{
		length += 1;
		i += 1;
	}
	return (length);
}



/**
 * forkExe - fork a process and exec command
 * @inputCmd: the command to be excutes
 * @argv: arr of str arg
 * @envp: environmental variable
 * Return: nothing void func
 */
int main(int argc, char *argv[], char *envir[])
{
    int i;

	for (i = 0; envir[i] != NULL; i++)
    {
        write(STDOUT_FILENO, envir[i], _strlen(envir[i]));
        write(STDOUT_FILENO, "\n", 1);
    }
    return (0);
}
