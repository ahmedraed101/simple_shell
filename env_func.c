#include "main.h"

/**
 * print_env - print the environment variables
 * Return: 0 on success, -1 on failure
*/
int print_env(void)
{
	char **env = environ;
	int i = 0;

	while (env[i])
		write(0, env[i], _strlen(env[i])), write(0, "\n", 1), i++;

	return (0);
}

/**
 * _getenv - a function that gets the value of environment variable
 * @name: the name of the environment variable
 * Return: the value of the environment variable
*/
char *_getenv(char *name)
{
	int i = 0;
	char **envp = environ;

	while (envp[i] != NULL)
	{
		if (_strcmp(name, envp[i]) != -1)
		{
			char *value;

			_strtok(envp[i], "=");
			value = _strtok(NULL, "=");

			return (value);
		}
		i++;
	}
	return (NULL);
}

/**
 * _setenv - sets the value of the environment variable
 * @name: the name of the environment variable
 * @value: the value of the environment variable
 * @overwrite: whether to overwrite the value of the environment variable
 * Return: 0 on success, -1 on failure
*/
int _setenv(char *name, char *value, int overwrite)
{
	int size;
	char *full_str, *eq_name, *full_name;

	if (name == NULL || value == NULL)
		return (-1);

	size = _strlen(name) + _strlen(value) + 2;
	full_str = malloc(sizeof(char) * size);
	if (full_str == NULL)
		return (-1);

	eq_name = _strcat(_strcpy(full_str, name), "=");
	full_name = _strcat(eq_name, value);

	if (_getenv(name) == NULL)
	{
		int result = putenv(full_name);

		if (result != 0)
		{
			free(full_name);
			return (-1);
		}
	}
	else if (overwrite != 0)
	{
		int result = putenv(full_name);

		if (result != 0)
		{
			free(full_name);
			return (-1);
		}
	}
	return (0);
}

/**
 * _unsetenv - remove environment variable
 * @name: name of the environment variable
 * Return: 0 on success, -1 on failure
*/

int _unsetenv(char *name)
{
	char **envp = environ;

	while (*envp != NULL)
	{
		char *current_value = *envp;
		int name_len = _strlen(name);

		if (_strcmp(name, current_value) == 1 && current_value[name_len] == '=')
		{
			char **next;

			free(_getenv(name));
			next = envp + 1;
			while (*next != NULL)
			{
				*envp = *next;
				envp++;
				next++;
			}
			*envp = NULL;
			return (0);
		}
		envp++;
	}
	return (-1);
}
