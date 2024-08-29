#include "main.h"

/**
 *
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

/**
 * int main(void)
{
	print_dir();

	return (0);
	}
*/
