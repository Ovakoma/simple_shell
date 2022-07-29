#include "shell.h"

/**
* prompt_user - prints $ to let user know the program is
* ready to take their input
* prints the prompt if the shell is in interactive mode
* Return: no return
*/
void prompt_user(void)
{
	if ((isatty(STDIN_FILENO) == 1) && (isatty(STDOUT_FILENO) == 1))
		flags.interactive = 1;
	if (flags.interactive)
		write(STDERR_FILENO, "$ ", 2);
}

/**
 * hsh_readline - reads input from stdin
 * ip: value from getline function
 * Return: input string
 */
char hsh_readline(int *ip)
{
	char *input = NULL;
	size_t bufsize = 0;

	ip = getline(&input, &bufsize, stdin);

	return (input);
}