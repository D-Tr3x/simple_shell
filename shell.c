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
 * check_exit - exits the shell if the input is "exit"
 * @line: buffer to be freed before exit;
 */
void check_exit(char *line)
{
	if (_strcmp(line, "exit\n") == 0)
	{
		free(line);
		exit(EXIT_SUCCESS);
	}
}

/**
 * fwxec - forks, waits and executes a command
 * @cmd: arguments list (commands)
 */
void fwxec(char *cmd)
{
	pid_t child_pid;
	int status;
	char *argv[2];

	argv[0] = cmd;
	argv[1] = NULL;

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
	char *line = NULL, *ptr;
	size_t len = 0;

	while (1)
	{
		read_line(&line, &len);
		check_exit(line);

		ptr = line;
		while (ptr[len] != '\n' && ptr[len] != '\0')
			len++;
		ptr[len] = '\0';

		if (access(line, X_OK) == 0)
			fwxec(line);
		else
			perror("Error");
	}

	free(line);
	exit(EXIT_SUCCESS);
}
