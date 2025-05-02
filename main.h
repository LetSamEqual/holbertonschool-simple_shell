#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>

extern char **environ;

char **arg_splitter(char *input);
void _getenv(void);
char **handle_input(void);
char *get_path(char *args);
void run_command(char *path, char **args, char **env);

#endif
