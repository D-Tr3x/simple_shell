#include "main.h"

/**
 * main - check the code
 */

/**
 * int main(int argc, char *argv[])
 * {
 *	printf("$ ");
 *	get_args(argc, argv);
 *		
 *	return (0);
 * }
 */

int main(int argc, char *argv[])
{
	if (argc > 2)
		exit(EXIT_FAILURE);
	
	printf("$ ");
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	while ((read = getline(&line, &len, stdin)) != -1)
	{
		printf("%s ", line);
		
		if (line[read - 1] == '\n')
			line[read - 1] = '\0';

		if (line == "exit")
			break;
	}
	printf("\n");

	free(line);
	exit(EXIT_SUCCESS);
}
