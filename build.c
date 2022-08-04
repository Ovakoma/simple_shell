#include "shell.h"

/**
 * check_builtins - checks if command is a builtin command
 * @cmd: command passed to function
 * Return: index of command
 */
builtin_t check_builtins(char *cmd)
{
        builtin_t builtins[] = {
                {"exit", exit_cmd},
                {"env", env_cmd},
                {NULL, NULL}
        };
        int i;
        for (i = 0; builtins[i].cmd; i++)
        {
                if (_strcmp(builtins[i].cmd, cmd) == 1)
                        return (builtins[i]);
        }
        return (builtins[i]);
}

/**
 * is_builtin - If command is a builtin command
 * @cmd: an array of command and its arguments
 * Return: function to be executed, else NULL
 */
int (*is_builtin(char **cmd))(char **, int, char *)
{
        builtin_t init = check_builtins(cmd[0]);

        if (init.cmd)
                return (init.f);

        return (NULL);
}

/**
 * env_cmd - funtion of env command
 * @cmd: Unused
 * @status: status
 * @filename: the name of the file
 * Return: 0(success)
 */
int env_cmd(char **cmd, int status, char *filename)
{
	int i = 0;

	(void) cmd;
	(void) status;
	(void) filename;

        while (environ[i])
        {
                print_st(environ[i]);
                _putchar('\n');
                i++;
        }
        return (0);
}

/**
 * exit_cmd - function of exit command
 * @cmd: an array of given command and its arguments
 * @status: status
 * @filename: name of the file
 * Return: exit with the status code given by user, or
 * previous execution status code
 */
int exit_cmd(char **cmd, int status, char *filename)
{
        int i;

        if (!cmd[1])
        {
            _free(cmd);
            exit(status);
        }
        while (cmd[1][i])
        {
                if (_isalpha(cmd[1][i]) && cmd[1][i] != '-')
                {
                    print_st(filename);
                    print_st(": ");
                    print_st(cmd[0]);
                    print_st("illegal number: ");
                    print_st(cmd[1]);
                    _putchar('\n');
                    return (1);
                }
                i++;
        }
        status = _atoi(cmd[1]);
        _free(cmd);

        exit(status);
}
