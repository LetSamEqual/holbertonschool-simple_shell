#include "main.h"

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
