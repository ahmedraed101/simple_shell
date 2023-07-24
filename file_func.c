#include "main.h"


char *find_path(char *file_name)
{
	return (file_name);
}
/**
char *old_find_path(char *file_name)
{
	char *file_path;
	struct stat st;
	int i = 0;

	if (stat(file_name, &st) == 0)
		return (file_name);
	char *paths = _getenv("PATH");
	char *path = _strtok(paths, ":");

	while (path)
	{
		struct stat st_path;
		file_path = get_full_path(path, file_name);

		if (stat(file_path, &st_path) == 0)
			return (file_path);
		path = _strtok(NULL, ":");
	}
	free(file_path);
	return (NULL);
}
*/


void run_file(char **args)
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == 0)
	{
		if (execve(args[0], args, environ) == -1)
			perror(_getenv("_"));
	}
	else
		wait(&status);
}


char *get_full_path(char *path, char *filename)
{
	char *return_p;
	int path_len = _strlen(path);
	int filename_len = _strlen(path);
	int file_path_len = path_len + filename_len + 2;
	char *file_path = malloc(sizeof(char) * file_path_len);

	if (file_path == NULL || path == NULL || filename == NULL)
		return (NULL);

	(return_p = file_path);
	while (*path != '\0')
	{
		*file_path = *path;
		path++;
		file_path++;
	}
	*file_path = '/';
	file_path++;
	while (*filename != '\0')
	{
		*file_path = *filename;
		filename++;
		file_path++;
	}
	*file_path = '\0';
	return (return_p);
}
