#include "main.h"

/**
 * _getenv - gets user environ
 *
 * Return: void
 */

void _getenv(void)
{
	char *args[] = {"env", NULL};

	execve("/usr/bin/env", args, environ);
}
