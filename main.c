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
		free(args);
		free(buffer);
	}

	buffer[input_len - 1] = '\0';

	args = arg_splitter(buffer);
	free(buffer);
	return (args);
}

char *get_path(char **args)
{
	char path[20] = "/bin/";
	int i, j;

	if (args[0][0] == '/')
		return (args[0]);

	for (i = 5, j = 0; args[0][j]; i++, j++)
	{
		path[i] = args[0][j];
	}

	path[i] = '\0';

	return (path);
}

void run_command(char *path, char **args, char **env)
{
	if (strcmp(args[1], "env"))
		_getenv();
	else if (strcmp(args[1], "exit"))
		return;
	else
		execve(path, args, env);
	perror("You've entered an invalid command dummy :( \n");
}


int main(void)
{
	char *buffer;
	size_t buf_size = 100;
	int input_len;
	int children = -1;
	char path[20] = "/bin/";
	char **args = {NULL};
	char **env = {NULL};
	pid_t id;
	int i, j;
	
	buffer = malloc(buf_size);
	if (!buffer)
	{
		perror("failed to allocate memory for buffer");
		return (0);
	}

	printf("\njanky shell $ ");
	input_len = getline(&buffer, &buf_size, stdin);

	if (input_len == -1)
	{
		printf("\nExited program\n"); 
		free(args);
		free(buffer);
		return (0);
	}

	if (buffer[input_len - 1] == '\n')
		buffer[input_len - 1] = '\0';

	args = arg_splitter(buffer);
	free(buffer);

	for (i = 5, j = 0; args[0][j]; i++, j++)
	{
		path[i] = args[0][j];
	}

	path[i] = '\0';

	id = fork();

	if (id == 0)
		execve(path, args, env);
	else
	{
		wait(&children);
		main();
	}

	return (0);
}
