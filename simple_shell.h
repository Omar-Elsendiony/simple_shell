#ifndef SIMPLE_SHELL_H_
#define SIMPLE_SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
int _strncmp(char *s1, char *s2, int n);
char *_strcatheap(char *dest, char *src);

#endif /*SIMPLE_SHELL_H_*/
