#include "main.h"

/**
 * run_command - runs command entered by user
 * @path: path to bin folder
 * @args: array of commands from user
 * @env: env variables passed from user
 *
 * Return: void
 */

void run_command(char *path, char **args, char **env)
{
	if (strcmp(args[0], "env") == 0)
		_getenv();
	else
		execve(path, args, env);
	perror("something's gone horribly wrong :( \n");
}
