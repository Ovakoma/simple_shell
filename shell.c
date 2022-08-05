#include "shell.h"

/**
 * main - Entry point
 * @ac: number of arguments passed to function
 * @av: arguments passed to function
 * Return: 0(suceess)
 */
int main(int ac __attribute__((unused)), char **av)
{
	char *input = NULL, **token = NULL;
	size_t bufsize = 0;
	ssize_t nread;
	int status, (*builtin)(char **, int, char*);

	while (1)
	{
		if (isatty(STDIN_FILENO))
			prompt_user();

		nread = getline(&input, &bufsize, stdin);
		if (nread == -1)
		{
			free(input);
			printf("\n...logging out");
			exit(EXIT_FAILURE);
		}
		if (*input == '\n' || *input == '\0')
			continue;
		
		input = rem_nl(input);
		token = parser(input);
		
		if (!token || !token[0])
			continue;
		builtin = is_builtin(token);
		if (builtin)
		{
			status = builtin(token, status, av[0]);
			_free(token);
			continue;
		}
		else
			execution(av[0], token);

		_free(token);
	}
    return (0);
}
