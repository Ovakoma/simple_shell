#include "shell.h"

/**
 * execution - executes commands entered by users
 *@cp: command
 *@cmd:vector array of pointers to commands
 * Return: 0
 */
void execution(char *cp, char **cmd)
{
	pid_t child_pid;
	int status;

	if (!*cmd)
		exit(98);
	child_pid = fork();
	if (child_pid < 0)
	{
		perror(cp);
		exit(98);
	}
	if (child_pid == 0)
	{
		if (strncmp(cmd[0], "./", 2) && strncmp(cmd[0], "/", 1))
			check_cmd_path(cmd);
		if (execve(cmd[0], cmd, environ) == -1)
		{
			perror(cp);
			_free(cmd);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
			return (WEXITSTATUS(status));
	}
}
/**
 * check_cmd_path - check if command is in path
 * @cmd: an array of command strings
 *
 * Return: 0 if found, else 1
 */
int check_cmd_path(**cmd)
{
	char *path, *val, *cmd_path;
	struct stat buff;

	*cmd_path = _getenv("PATH");
	val = strtok(path, ":");
	while (value)
	{
		cmd_path = build_path(*cmd, val);
		if (stat(cmd_path, &buff) == 0)
		{
			*cmd = _strdup(cmd_path);
			free(cmd_path);
			return (0);
		}
		free(cmd_path);
		val = strtok(NULL, ":");
	}
	return (1);
}
/**
 * build_path - build the path to a command
 * @cmd: the given command
 * @val: the path to build for @token
 *
 * Return: @val/@cmd - the path of command
 */
char build_path(char *cmd, char *val)
{
	size_t len = _strlen(val) + _strlen(cmd) + 2;
	char *cm_d = malloc(sizeof(char) * len);

	if (!cmd)
		return (NULL);
	memset(cm_d, 0, len);

	cm_d = _strcat(cm_d, val);
	cm_d = _strcat(cm_d, "/");
	cm_d = _strcat(cm_d, cmd);

	return (cm_d);
}