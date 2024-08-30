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
		exit(EXIT_FAILURE);
	}

	return (read);
}
/**
 * tokenize - separates a string into tokens
 * @path: the source of the string to be tokenized
 * @argv: array for storing tokenized string
 *
 * Return: the tokenized string
 */

void tokenize(char *path, char *argv[])
{
	char *token;
	int i = 0;

	token = strtok(path, " \n");
	while (token != NULL)
	{
		argv[i] = token;
		i++;
		token = strtok(NULL, " \n");
	}

	argv[i] = NULL;
}

/**
 * check_exit - exits the shell if the input is "exit"
 * @argv: arguments list
 * @line: buffer to be freed before exit;
 */
void check_exit(char **argv, char *line)
{
	if (argv[0] && _strcmp(argv[0], "exit") == 0)
	{
		free(line);
		exit(EXIT_SUCCESS);
	}
}
/**
 * handle_path - handles the full path of a command
 * @argv: double pointer to arguments (command)
 */
void handle_path(char **argv)
{
	char *path_env, *dup_path, *path_token, path[1024];

	if (!_strchr(argv[0], '/'))
	{
		path_env = _getenv("PATH");
		dup_path = _strdup(path_env);
		path_token = strtok(dup_path, ":");
		while (path_token != NULL)
		{
			sprintf(path, "%s/%s", path_token, argv[0]);

			if (access(path, X_OK) == 0)
			{
				argv[0] = path;
				break;
			}
			path_token = strtok(NULL, ":");
		}
		free(dup_path);
	}
}

/**
 * fwxec - forks, waits and executes a command
 * @argv: arguments list (commands)
 */
void fwxec(char **argv)
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

