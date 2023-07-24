#include "main.h"

/**
 * main - the main program loop
 * Return: int
*/

int main(void)
{
	char *line = NULL;
	size_t len = 0;
	int exit_status = 0;

	while (1)
	{
		char *trimed_line;
		ssize_t n;
		int status;

		if (isatty(STDIN_FILENO))
			write(0, "$ ", 2);
		n = getline(&line, &len, stdin);

		if (n == -1)
		{
			if (isatty(STDIN_FILENO))
				write(0, "\n", 1);
			free(line);
			return (0);
		}
		line[n - 1] = '\0';
		trimed_line = trim_space(line);
		if (trimed_line == NULL)
			continue;

		status = handel_line(trimed_line);

		if (status == 1)
			break;
		else if (status > 1)
		{
			exit_status = status;
			break;
		}
	}
	free(line);
	return (exit_status);
}
