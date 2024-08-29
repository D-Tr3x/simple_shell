#include "main.h"

int main(int argc, char *argv[])
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	char *token;
	
	if (argc != 1)
		exit(EXIT_FAILURE);

	while (1)
	{
		printf("$ ");
		read = getline(&line, &len, stdin);

		if (read == -1)
		{
			free(line);
			exit(EXIT_FAILURE);
		}
		token = strtok(line, " \n");
		while (token != NULL)
		{
			printf("%s\n", token);
			token = strtok(NULL, " \n");
		}
	}

	free(line);
	exit(EXIT_SUCCESS);
}
