#include "main.h"

/**
 * print_dir - prints the path of a directory
 *
 * Return: Nothing
 */
void print_dir(void)
{
	char *path, *directory;

	path = _getenv("PATH");
	if (path == NULL)
	{
		printf("PATH NOT FOUND");
		exit(EXIT_FAILURE);
	}

	directory = strtok(path, ":");
	while (directory != NULL)
	{
		printf("%s\n", directory);
		directory = strtok(NULL, ":");
	}
}
