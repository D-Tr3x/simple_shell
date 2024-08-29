#include "main.h"

extern char **environ;

/**
 *
 */
int _setenv(const char *name, const char *value, int overwrite)
{
	char **env, *var, *start;
	size_t len1, len2, i, j, k;
	int status = 0;

	if (name == NULL || value == NULL)
		return (-1);

	len1 = 0;
	while (name[len1] != '\0')
		len1++;

	len2 = 0;
	while (value[len2] != '\0')
		len2++;

	var  = malloc(len1 + len2 + 2);
	if (var == NULL)
		return (-1);

	i = 0;
	while (i < len1)
	{
		var[i] = name[i];
		i++;
	}
	var[i++] = '=';

	j = 0;
	while (j < len2)
	{
		var[i++] = value[j++];
	}
	var[i] = '\0';


	env = environ;
	while (*env)
	{
		start = *env;
		k = 0;

		while (start[k] == '=' && start[k] != '\0')
			k++;
	}
}
