#include "main.h"

/**
 * _strchr - checks for characters in the string
 * @str: string to be searched
 * @c: character to search for
 *
 * Return: pointer to first occurence or NULL
 */
char *_strchr(const char *str, char c)
{
    while(*str != '\0')
    {
        if (*str == c)
            return ((char *)str);
        str++;
    }

    return (NULL);
}

/**
 * _strcmp - compares two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: 0 on match, or their inrteger difference
 */
int _strcmp(const char *s1, const char *s2)
{
        while ((*s1 == *s2) && *s1)
        {
                s1++;
                s2++;
        }
        return *(unsigned char *)s1 - *(unsigned char *)s2;
}

/**
 * _strdup - duplicates a string
 * @str: pointer to the string to be duplicated
 *
 * Return: pointer to duplicated string or NULL
 */
char *_strdup(const char *str)
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

/**
 * _strcmp - compares two strings up to a specified length
 * @s1: first string
 * @s2: second string
 * @n: maximum number of characters to compare
 *
 * Return: 0 if equal, or the integer difference
 */
int _strncmp(const char *s1, const char *s2, size_t num)
{
	while (num > 0)
	{
		if ((unsigned char)*s1 != (unsigned char)*s2)
			return (*s1 - *s2);

		if (*s1 == '\0' || *s2 == '\0')
			return ((unsigned char)*s1 - (unsigned char)*s2);

		s1++;
		s2++;
		num--;
	}
	return (0);
}
