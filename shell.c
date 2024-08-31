#include "main.h"

/**
 * read_line - reads a line of input
 * @line: double pointer to buffer where read input will be stored
 * @len: pointer to length of the buffer
 *
 * Return: number of characters read
 */
ssize_t read_line(char **line, size_t *len)
{
	ssize_t read;

	printf("$ ");
	read = getline(line, len, stdin);
	if (read == -1)
	{
		free(*line);
		if (feof(stdin))
			exit(EXIT_SUCCESS);
		else
		{
			perror("Error");
			exit(EXIT_FAILURE);
		}
	}

	return (read);
}

/**
 * tokenize - separates a string into tokens
 * @line: the source of the string to be tokenized
 * @argv: array for storing tokenized string
 *
 * Return: the tokenized string
 */
void tokenize(char *line, char *argv[])
{
	char *token;
	int i = 0;

	token = strtok(line, "\n");
	while (token != NULL)
	{
		argv[i++] = token;
		token = strtok(NULL, "\n");
	}
	argv[i] = NULL;
}

/**
 * fwxec - forks, waits and executes a command
 * @cmd: arguments list (commands)
 */
void fwxec(char *argv[])
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}

	if (child_pid == 0)
	{
		if (execve(argv[0], argv, NULL) == -1)
		{
			perror("Error");
			exit(EXIT_FAILURE);
		}
	}
	else
		wait(&status);
}

/**
 * main - intializes an interactive shell
 *
 * Return: corresponding output of the shell
 */
int main(void)
{
	ssize_t read;
	char *line = NULL, *argv[99];
	size_t len = 0;

	while (1)
	{
		read = read_line(&line, &len);
		if (read == -1)
		{
			free(line);
			exit(EXIT_FAILURE);
		}

		tokenize(line, argv);
		if (argv[0] == NULL)
			continue;

		fwxec(argv);
	}

	free(line);
	exit(EXIT_SUCCESS);
}
