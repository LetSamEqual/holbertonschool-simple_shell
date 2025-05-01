#include "main.h"

void _getenv(void)
{
	char *args[] = {"env", NULL};
	execve("/usr/bin/env", args, environ);
}
