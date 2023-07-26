#include "main.h"

#define MAX_ARG 100

/**
 * handel_line - function handels the input until execve
 * @line: the input form user
 * Return: an int to decide to exit or not
 */
int handel_line(char *line)
{
	char *command;
	char **args;

	args = line_args(line);
	if (args == NULL)
		return (0);
	command = args[0];
	if (command == NULL)
		return (0);

	if (_strcmp(command, "exit") == 1)
	{
		int i = 1;

		if (args[1] != NULL)
			i = atoi(args[1]);
		free(args);
		return (i); }

	if (execute_command(args) == 0)
	{
		free(args);
		return (0); }
	command = find_path(command);
	if (command != NULL)
	{
		args[0] = command;
		if (execute_command(args) == 0)
		{
			free(command);
			free(args);
			return (0); }
	} else
		perror(getenv("_"));

	free(command);
	free(args);
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
		perror(getenv("_"));
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
