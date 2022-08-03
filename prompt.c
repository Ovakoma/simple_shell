#include "shell.h"

/**
* prompt_user - prints $ to let user know the program is
* ready to take their input
* prints the prompt if the shell is in interactive mode
* Return: no return
*/
void prompt_user(void)
{
	int slen, tlen, plen;
	char *s = _getenv("USER"), *t = "> ", *p = _getenv("NAME"), *prompt;

	slen = _strlen(s);
	plen = _strlen(p);
	tlen = _strlen(t);

	prompt = malloc(sizeof(char) * (slen + plen + tlen));
	if (!s || !p || !prompt)
	{
		printf("cisfun$ ");
		return;
	}
	prompt = _strcpy(prompt, p);
	prompt = _strcat(prompt, "@");
	prompt = _strcat(prompt, s);
	prompt = _strcat(prompt, t);

	print_st(prompt);
	free(prompt);
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

	while (1)
	{
		nread = getline(&input, &bufsize, stdin);
		if (nread == -1)
		{
			printf("\n...logging out");
			return;
		}
		if (*input == '\n' || *input == '\0')
			continue;
	}
	input = rem_nl(input);
	token = parser(input);

	if (!token || !token[0])
		continue;
}