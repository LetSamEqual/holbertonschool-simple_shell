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

	if (input_len == -1)
	{
		free(buffer);
		return (NULL);
	}

	buffer[input_len - 1] = '\0';

	args = arg_splitter(buffer);
	if (!args)
		return (NULL);
	return (args);
}
