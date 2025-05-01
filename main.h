#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

extern char **environ;

char **arg_splitter(char *input);
void _getenv(void);

#endif
