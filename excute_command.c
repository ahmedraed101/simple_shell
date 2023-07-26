#include "main.h"


/**
 * execute_command - function to execute a command
 * @args: the command to execute
 * @prog_name: the name of the program to use in perror
 * Return: 0 on success, -1 on failure
*/
int execute_command(char **args, char *prog_name)
{
	pid_t child_pid;
	int status;
	char *error_message = _concat(prog_name, ": 1: ", args[0]);

	if (access(args[0], F_OK) != 0 || access(args[0], X_OK) != 0)
	{
		perror(error_message);
		free(error_message);
		return (-1); }

	child_pid = fork();
	if (child_pid == 0)
	{
		if (execve(args[0], args, environ) == -1)
		{
			perror(error_message);
			free(error_message);
			exit(EXIT_FAILURE);
		}
		exit(EXIT_SUCCESS);
	}
	else if (child_pid == -1)
	{
		free(error_message);
		return (-1);
	}
	else
	{
		free(error_message);
		waitpid(child_pid, &status, 0);
		return (-1);
	}
	free(error_message);
	return (0);
}
