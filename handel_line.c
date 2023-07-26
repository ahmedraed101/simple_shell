#include "main.h"

#define MAX_ARG 100

/**
 * handel_line - function handels the input until execve
 * @line: the input form user
 * @prog_name: the name of the program to use in perror
 * Return: an int to decide to exit or not
 */
int handel_line(char *line, char *prog_name)
{
	char *command;
	char **args;
	static int last_stat = 1;

	args = line_args(line);
	if (args == NULL)
		return (0);
	command = args[0];
	if (command == NULL)
		return (0);
	if (_strcmp(command, "exit") == 1)
	{
		int i = last_stat;

		if (args[1] != NULL)
			i = atoi(args[1]);
		free(args);
		return (i); }
	if (builtin(args, prog_name) == 0)
	{
		last_stat = 1;
		return (0); }
	if (execute_command(args, prog_name) == 0)
	{
		last_stat = 1;
		free(args);
		return (0); }
	command = find_path(command, prog_name);
	if (command != NULL)
	{
		args[0] = command;
		if (execute_command(args, prog_name) == 0)
		{
			last_stat = 1;
			free(command), free(args);
			return (0); }
	}
	free(command), free(args);
	last_stat = 127;
	return (0);
}

/**
 * line_args - function that splits the input into arguments
 * @line: the input
 * Return: an array of strings
*/
char **line_args(char *line)
{
	char *token;
	char **args;
	int i = 0;
	int j = 0;

	while (line[j])
	{
		if (line[j] == '#')
		{
			if (j == 0)
				return (NULL);
			line[j] = '\0';
			break;
		}
		j++;
	}

	args = malloc(MAX_ARG * sizeof(char *));
	if (args == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	token = _strtok(line, " ");
	while (token != NULL && i < MAX_ARG - 1)
	{
		if (_strcmp(token, " ") != 1)
			args[i++] = token;
		token = _strtok(NULL, " ");
	}
	args[i] = NULL;
	return (args);
}

/**
 * trim_space - function to trim whitespace
 * @str: a string to trim
 * Return: the trimed string or Null
*/
char *trim_space(char *str)
{
	if (str[0] == '\0')
		return (NULL);
	while (*str != '\0')
	{
		if (*str != ' ')
			return (str);

		str++;
	}
	return (str);
}
