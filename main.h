#ifndef SIMPLE_SHELL_H_
#define SIMPLE_SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
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
void free2dArr(char **arr);
#endif /*SIMPLE_SHELL_H_*/
