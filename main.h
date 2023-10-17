#ifndef SIMPLE_SHELL_H_
#define SIMPLE_SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>
#define SIZE 4096
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
int _strncmp(char *s1, char *s2, int n);
char *_strcatheap(char *dest, char *src);
char *_strncpy(char *dest, char *src, int n);
int lett_count(char *st, char del);
int word_count(char *wo, char del);
char **slicing(char *str, char del);
char **pathSlice(char **env);
void forkExe(char *inputCmd, char *argv[], char *env[]);
void forkExe2(char *inputCmd, char *argv[], char *envp[]);
void free2dArr(char **arr);
void replaceNewLine(char *str);

/* omar functions */
int _getline(char **string, size_t *n, int fd);
void handler(int sig);
int changeDirectory(char **arglist, char *buffer, char *homePath);
char *getHomePath(char ** envir);
/* end of omar functions */

typedef struct cmdType
{
	char *name;
	int (*func)(char *argv[], char *env[]);
} cmdType;

extern char **environ;
#endif /*SIMPLE_SHELL_H_*/
