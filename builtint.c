#include "main.h"

/**
 * builtin - a function that runs env getenv and setenv
 * @args: the arguments of the program
 * @prog_name: the program name for errors
 * Return: 0 on success or -1 on filure
 */
int builtin(char **args, char __attribute__((unused)) *prog_name)
{
	if (_strcmp(args[0], "env") == 1)
	{
		if (args[1] != NULL)
		{
			char *err = _concat("env: '", args[1], "': No such file or directory\n");

			write(0, err, _strlen(err));
			free(err);
			return (0); }
		print_env();
		free(args);
		return (0);

	} else if (_strcmp("setenv", args[0]) == 1)
	{
		if (args[1] == NULL || args[2] == NULL)
		{
			write(2, "setenv VARIABLE VALUE\n", 22);
			free(args);
			return (0); }
		if (_setenv(args[1], args[2], 1) == 0)
		{
			free(args);
			return (0); }
		write(2, "setenv error\n", 13);
		free(args);
		return (0);
	} else if (_strcmp(args[0], "unsetenv") == 1)
	{
		if (args[1] ==  NULL)
		{
			free(args);
			write(2, "unsetenv VARIABLE_NAME\n", 23);
			return (0); }
		if (_unsetenv(args[1]) == 0)
		{
			free(args);
			return (0); }
		write(2, "unsetenv error\n", 15); }
	return (-1);
}
