#include "main.h"

char **arg_splitter(char *input)
{
	char **token_array;
	char *token;
	int i;

	token_array = malloc(100);
	if (!token_array)
	{
		perror("Failed to allocate memory");
		return (NULL);
	}

	token = strtok(input, " ");

	for (i = 0; token; i++)
	{
		token_array[i] = token;
		token = strtok(NULL, " ");
	}
	
	token_array[i] = NULL;

	return (token_array);
}
