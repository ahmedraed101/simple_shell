#include "main.h"


#include "main.h"
/**
 * find_path - resolve the path of command execution
 * @command: command to be executed
 * Return: path or NULL if not.
 */
char *find_path(char *command)
{
	char *path = getenv("PATH");
	char *token, *temp, *c_path;

	temp = _strdup(path);
	if (temp == NULL)
	{
		perror(getenv("_"));
		exit(EXIT_FAILURE);
	}
	token = strtok(temp, ":");
	while (token != NULL)
	{
		c_path = _concat(token, "/", command);
		if (c_path == NULL)
		{
			perror(getenv("_"));
			exit(EXIT_FAILURE);
		}
		if (access(c_path, F_OK) == 0 && access(c_path, X_OK) == 0)
		{
			free(temp);
			return (c_path);
		}
		free(c_path);
		token = strtok(NULL, ":");
	}
	free(temp);
	return (NULL);
}


/**
 * _concat - joins two strings with a slash between them
 * @str1: first string
 * @sep: /
 * @str2: second string
 * Return: NULL on error or the concattenated string on success.
 */

char *_concat(char *str1, char *sep, char *str2)
{
	char *new_str;
	size_t len1, len2, len3, i, j;

	len1 = _strlen(str1);
	len2 = _strlen(sep);
	len3 = _strlen(str2);
	new_str = malloc(len1 + len2 + len3 + 1);

	if (!new_str)
		return (NULL);
	for (i = 0; str1[i]; i++)
		new_str[i] = str1[i];
	j = i;
	for (i = 0; sep[i]; i++)
		new_str[j + i] = sep[i];
	j += i;
	for (i = 0; str2[i]; i++)
		new_str[j + i] = str2[i];
	j += i;
	new_str[j] = '\0';
	return (new_str);
}


/**
 * _strdup - copies a string
 * @str: string to be copied
 * Return: copied string
 */
char *_strdup(char *str)
{
	char *new_str;
	int len = _strlen(str) + 1;

	new_str = malloc(len);
	if (new_str == NULL)
		return (NULL);
	_memcpy(new_str, str, len);
	return (new_str);
}

/**
 *_memcpy - copies a memory block
 *@dest: pointer to new memory block
 *@src: pointer to source memory block
 *@n: the number of bytes to be copied
 *Return: Void.
 */

void *_memcpy(void *dest, void *src, int n)
{
	char *d = dest;
	const char *s = src;
	int i;

	for (i = 0; i < n; i++)
	{
		d[i] = s[i];
	}
	return (dest);
}
