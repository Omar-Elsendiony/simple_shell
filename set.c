#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern char **environ;

int main(int argc, char **argv)
{
	int i = 0;
	char **p;

	p = malloc(sizeof(char *) * 3);
	p[0] = "hello";
	p[1] = "bebo";
	p[2] = NULL;
	environ = p;
	while (environ[i])
	{
		printf("%s\n", environ[i]);
		++i;
	}
}
