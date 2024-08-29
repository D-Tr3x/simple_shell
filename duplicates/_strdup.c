#include "main.h"

/**
 * _strdup - duplicates a string
 * @str: pointer to the string to be duplicated
 *
 * Return: pointer to duplicated string or NULL
 */
char *_strdup(char *str)
{
	unsigned int i = 0, size;
	char *dup;

	if (str == NULL)
		return (NULL);

	while (str[i])
		i++;

	size = i + 1;

	dup = malloc(sizeof(char) * size);
	if (dup == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		dup[i] = str[i];

	return (dup);
}
