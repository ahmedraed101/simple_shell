#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include "errno.h"

extern char **environ;

int _strcmp(char *s1, char *s2);
char *_strtok(char *str, char *delim);
int _strlen(char *str);
char *_strcpy(char *, char *);
char *_strcat(char *dest, char *src);

char *trim_space(char *str);
int handel_line(char *line, char *prog_name);
char **line_args(char *line);

int print_env(void);
char *_getenv(char *name);
int _setenv(char *name, char *value, int overwrite);
int _unsetenv(char *name);

char *find_path(char *command, char *prog_name);
char *_concat(char *str1, char *sep, char *str2);
void run_file(char **);
char *_strdup(char *str);
void *_memcpy(void *dest, void *src, int n);

int builtin(char **args, char *porg_name);

int execute_command(char **args, char *prog_name);
#endif
