#include "main.h"

/**
 *
 */
int main(int ac, char **av)
{
	const char *filename;
	struct stat st;

	filename = av[1];
	if (stat(filename, &st) > 0)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}

	printf("Filename: %s\n", filename);
	printf("Permissions: %o\n", st.st_mode & 0777);

	return (0);
}
