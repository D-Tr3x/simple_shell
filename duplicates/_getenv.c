#include "main.h"


extern char **environ;

/**
 * _getenv - searches the environment list
 * to find the environment variable name
 * @name: the string that is searched
 *
 * Return: pointer to value in environment or NULL
 */
char *_getenv(const char *name)
{
	unsigned int i, j;
	char *var;

	i = 0;
	while (environ[i] != NULL)
	{
		var = environ[i];
		j = 0;
		while (var[j] == name[j] && name[j])
		{
			j++;
		}

		if (var[j] == '=' && name[j] == '\0')
			return (var + j + 1);
		i++;
	}
	return (NULL);
}
