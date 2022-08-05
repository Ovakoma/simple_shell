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
		printf("#cisfun$ ");
		return;
	}
	prompt = _strcpy(prompt, p);
	prompt = _strcat(prompt, "@");
	prompt = _strcat(prompt, s);
	prompt = _strcat(prompt, t);

	print_st(prompt);
	free(prompt);
}