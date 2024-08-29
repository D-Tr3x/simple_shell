#include "main.h"

/**
 * _strcpy -
 *
 */
void _strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

/**
 *
 */
char **tokenize(char *path)
{
	char **paths;
	char *token;
	int len, i = 0, size = 1;

	paths = malloc(1 * sizeof(char *));
	if (paths == NULL)
		return (NULL);

	while (str[length] != '\0')
		len++;
	
	token = strtok(path, ":");
	while (token != NULL)
	{
		size = len + 1;
		paths[i] = malloc(size * sizeof(char *));
		if (paths[i] == NULL)
		{
			free(paths);
			return (NULL);
		}
		_strcpy(paths[i], token);
		i++;
		token = strtok(NULL, ":");
	}

	paths[i] = NULL;
	return (paths);
}
