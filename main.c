#include "main.h"

/**
 * main - initialized an interactive shell
 *
 * Return: the corresponding output of the shell command
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	char *argv[64];

	while (1)
	{
		read_line(&line, &len);
		tokenize(line, argv);
		check_exit(argv, line);
		handle_path(argv);
		fwxec(argv);
	}

	free(line);
	exit(EXIT_SUCCESS);
}
