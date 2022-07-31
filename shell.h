#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

/* Helper string manipualtion functions */
char *_strcpy(char *dest, char *str);
char *_strcmp(char *str1, char *str2);
char *_strcat(char *s1, char *s2);
int *_strlen(char *str);