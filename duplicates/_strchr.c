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
