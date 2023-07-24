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


extern char **environ;

int _strcmp(char *s1, char *s2);
char *_strtok(char *str, char *delim);
int _strlen(char *str);
char *_strcpy(char *, char *);
char *_strcat(char *dest, char *src);

char *trim_space(char *str);
int handel_line(char *line);
char **line_args(char *line);

char *_getenv(char *name);
int _setenv(char *name, char *value, int overwrite);
int _unsetenv(char *name);

char *get_full_path(char *path, char *filename);
char *find_path(char *);
void run_file(char **);

#endif
