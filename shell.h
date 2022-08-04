#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/stat.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

extern char **environ;

/**
 * struct builtin_t - struct for builtin commands
 * @cmd: the command's name
 * @f: pointer to function
 */
typedef struct builtin_t
{
    char *cmd;
    int (*f)(char **, int, char *);
} builtin_t;

int _putchar(char c);

/* Helper string manipualtion functions */
char *_strcpy(char *dest, char *str);
int _strcmp(char *str1, char *str2);
char *_strcat(char *s1, const char *s2);
int _strlen(char *str);
char *_strdup(char *str);
int _atoi(char *str);
int _isalpha(char c);

void _free(char** buff);
void free_p(char *ptr);

void hsh_readline(void);
void prompt_user(void);
int print_st(char *c);
char **parser(char *input);
char *rem_nl(char *input);
char *_getenv(const char *var);

builtin_t check_builtins(char *cmd);
int (*is_builtin(char **cmd))(char **, int, char *);
int env_cmd(char **, int, char *);
int exit_cmd(char **, int, char *);
void execution(char *cp, char **cmd);

#endif
