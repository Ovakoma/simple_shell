#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

/* Helper string manipualtion functions */
char *_strcpy(char *dest, char *str);
int _strcmp(char *str1, char *str2);
char *_strcat(char *s1, const char *s2);
int _strlen(char *str);

void _free(char** buff);

void hsh_readline(void);
void prompt_user(void);
int print_st(char *c);
void hsh_exec(char **argv);
void parser(char *input, char *bufcpy);

#endif
