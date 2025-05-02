#include "main.h"

/**
 * handle_input - Reads a command from the user
 *
 * Return: array of args if succesful or null if not
 */

char **handle_input(void)
{
	char *buffer;
	char **args;
	size_t buf_size;
	int input_len;

	buf_size = 100;
	buffer = malloc(buf_size);
	if (!buffer)
	{
		perror("failed to allocate memory for buffer");
		return (NULL);
	}
	input_len = getline(&buffer, &buf_size, stdin);

	if (input_len == -1 && !isatty(STDIN_FILENO))
	{
		printf("\nExited program\n");
		return (NULL);
	}

	buffer[input_len - 1] = '\0';

	args = arg_splitter(buffer);
	if (!args)
		return (NULL);
	return (args);
}

/**
 * get_path - returns absolute path to bin folder
 * @args: first arg in array of arg pointing to first command user entered
 *
 * Return: path to bin folder
 */

char *get_path(char *args)
{
	char *path;
	char *default_path = "/bin/";
	int i, j, len;

	if (strncmp(args, default_path, 5) == 0)
		return (args);

	len = 0;

	while (args[len])
		len++;

	path = malloc(5 + len + 1);

	if (!path)
	{
		perror("Failed to allocate memory for path");
		return (NULL);
	}

	for (i = 0; i < 5; i++)
		path[i] = default_path[i];

	for (i = 5, j = 0; args[j]; i++, j++)
	{
		path[i] = args[j];
	}

	path[i] = '\0';
	return (path);
}

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

/**
 * free_args - frees memory
 * @args: array of args passed by user
 *
 * Return: void
 */

void free_args(char **args)
{
	int i;

	for (i = 0; args[i]; i++)
		free(args[i]);
}

/**
 * main - entry point
 *
 * Return: 0 if succesful or 1 if failed
 */

int main(void)
{
	int children = -1;
	char *path;
	char **args;
	char **env = {NULL};
	pid_t id;
	struct stat st;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("\njanky shell $ ");
		args = handle_input();
		if (!args)
		{
			return (1);
		}
		if (strcmp(args[0], "exit") == 0)
		{
			return (0);
		}
		path = get_path(args[0]);

		if (stat(path, &st) != 0)
			perror("You've entered an invalid command dummy :( \n");
		else
		{
			id = fork();

			if (id == 0)
				run_command(path, args, env);
			else
				wait(&children);
		}
	}
	return (0);
}
