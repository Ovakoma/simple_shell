#include "shell.h"

/**
 * main - Entry point
 * @argc: number of arguments passed to function
 * @argv: arguments passed to function
 * Return: 0(suceess)
 */
int main(int argc __attribute__((unused)), char **argv)
{
    while (1)
    {
        if (isatty(STDIN_FILENO))
            prompt_user();
        hsh_readline();
    }

    return 0;
}