#include "main.h"


/**
 * execute_command - function to execute a command
 * @args: the command to execute
 * Return: 0 on success, -1 on failure
*/
int execute_command(char **args)
{
	pid_t child_pid;
	int status;

	if (access(args[0], F_OK) != 0 || access(args[0], X_OK) != 0)
		return (-1);

	child_pid = fork();
	if (child_pid == 0)
	{
		if (execve(args[0], args, environ) == -1)
		{
			exit(EXIT_FAILURE);
		}
		exit(EXIT_SUCCESS);
	}
	else if (child_pid == -1)
	{
		return (-1);
	}
	else
	{
		waitpid(child_pid, &status, 0);
		return (-1);
	}
	return (0);
}
