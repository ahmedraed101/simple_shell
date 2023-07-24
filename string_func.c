#include "main.h"

char *_strcat(char *dest, char *src)
{
	char *destp = dest;
	char *srcp = src;

	while (*destp != '\0')
		destp++;
	while (*srcp != '\0')
	{
		*destp = *srcp;
		destp++;
		srcp++;
	}
	*destp = '\0';
	return (dest);
}


int _strlen(char *str)
{
	int len = 0;

	while (str[len] != '\0')
		len++;

	return (len);
}

int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (-1);
		i++;
	}
	return (1);
}

/**
 * _strtok - a function that tokenizes a str into strings
 * @str: the string to tokenize
 * @del: the delimiter
 *
 * Return: the tokenized string
*/

char *_strtok(char *str, char *del)
{
	static char *last_token;
	char *token;

	if (str != NULL)
		last_token = str;
	else if (last_token == NULL)
		return (NULL);

	token = last_token;
	while (*last_token != '\0')
	{
		char *d = del;

		while (*d != '\0')
		{
			if (*last_token == *d)
			{
				*last_token = '\0';
				last_token++;
				if (*token != '\0')
				{
					return (token);
				}
				else
				{
					token = last_token;
					break;
				}
			}
			d++;
		}
		last_token++;
	}
	if (*token == '\0')
	{
		return (NULL);
	}
	last_token = NULL;
	return (token);
}

char *_strcpy(char *dest, char *src)
{
	int i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return dest;
}
