#include "shell.h"

/**
* prompt_user - prints $ to let user know the program is
* ready to take their input
* prints the prompt if the shell is in interactive mode
* Return: no return
*/
void prompt_user(void)
{
	unsigned int flags = 0;

	if ((isatty(STDIN_FILENO) == 1) && (isatty(STDOUT_FILENO) == 1))
		flags = 1;
	if (flags)
		write(STDERR_FILENO, "$ ", 2);
}

/**
 * hsh_readline - reads input from stdin
 * Return: void
 */
void hsh_readline(void)
{
	char *input = NULL, *bufcpy = NULL;
	size_t bufsize = 0;
	ssize_t nread;

	nread = getline(&input, &bufsize, stdin);
	if (nread == -1)
	{
		printf("\n...logging out");
		return;
	}
	
	bufcpy = malloc(sizeof(char) * nread);
	_strcpy(bufcpy, input);

	parser(input, bufcpy);

	free(input);
	free(bufcpy);
}