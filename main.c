#include "main.h"

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
    printf("%i\n", input_len);

    if (input_len == -1)
    {
        printf("\nExited program\n"); 
        free(buffer);
        return (0);
    }
    if (buffer[input_len - 1] == '\n')
	    buffer[input_len - 1] = '\0';
    printf("%s", buffer);

    args = arg_splitter(buffer);

    for (i = 5, j = 0; args[0][j]; i++, j++)
    {
        path[i] = args[0][j];
	}
    path[i] = '\0';

    id = fork();

    if (id == 0)
    {
        execve(path, args, env);
    }
    else
    {
        wait(&children);
	main();
    }

    return (0);
}
