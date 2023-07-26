#include "main.h"

/**
 * builtin - a function that runs env getenv and setenv
 * @args: the arguments of the program
 * @prog_name: the program name for errors
 * Return: 0 on success or -1 on filure
 */
int builtin(char **args, char *prog_name)
{
	pid_t child_pid;
	int status;

	if (_strcmp(args[0], "env") == 1)
	{
		if (args[1] != NULL)
		{
			char *err = _concat("env: '", args[1], "': No such file or directory\n");

			write(0, err, _strlen(err));
			free(args);
			free(err);
			return (0); }
		child_pid = fork();
		if (child_pid == 0)
		{
			print_env();
			exit(0); }
		else
		{
			wait(&status);
			free(args); }
		return (0);

	} else if (_strcmp(args[0], "setenv") == 1)
	{
		write(0, prog_name, _strlen(prog_name));
	} else if (_strcmp(args[0], "unsetenv") == 1)
	{
	}
	return (-1);
}
