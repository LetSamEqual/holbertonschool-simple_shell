#include "main.h"

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
		return(NULL);
	}
	input_len = getline(&buffer, &buf_size, stdin);

	if (input_len == -1)
	{
		printf("\nExited program\n"); 
		free(buffer);
	}

	buffer[input_len - 1] = '\0';

	args = arg_splitter(buffer);
	return (args);
}

char *get_path(char *args)
{
	char *path;
	char *default_path = "/bin/";
	int i, j, len;

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

void run_command(char *path, char **args, char **env)
{
	if (strcmp(args[0], "env") == 0)
		_getenv();
	else if (strcmp(args[0], "exit") == 0)
		return;
	else
		execve(path, args, env);
	perror("You've entered an invalid command dummy :( \n");
}

int main(void)
{
	int children = -1;
	char *path;
	char **args;
	char **env = {NULL};
	pid_t id;
	
	printf("\njanky shell $ ");
	args = handle_input();
	if (args[0][0] == '/')
		path = args[0];
	else
		path = get_path(args[0]);

	id = fork();

	if (id == 0)
		run_command(path, args, env);
	else
	{
		wait(&children);
		main();
	}

	return (0);
}
