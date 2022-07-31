#include "shell.h"

/**
 * parser - removes delimeters(space) and newline
 * from command input for execution
 * @input: string input being received 
 * @bufcpy: copy of string input for other purposes
 * Return: void
 */
 void parser(char *input, char *bufcpy)
 {
    char *tokens, delim[] = " \n", **argv = NULL;
    int n_token = 0, i;

    
 }