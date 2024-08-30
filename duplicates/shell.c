#include "main.h"

/**
 * tokenize - separates a string into tokens
 * @path: the source of the string to be tokenized
 *
 * Return: the tokenized string
 */

char **tokenize(char *path)
{
	char **paths, *token;
	int len = 0, i = 0, size = 1;

	paths = malloc(1 * sizeof(char *));
	if (paths == NULL)
		return (NULL);

	while (path[len] != '\0')
		len++;

	token = strtok(path, " \n");
	while (token != NULL)
	{
		size += len;
		paths[i] = malloc(size * sizeof(char *));
		if (paths[i] == NULL)
		{
			free(paths);
			return (NULL);
		}
		_strcpy(paths[i], token);
		i++;
		token = strtok(NULL, " \n");
	}

	paths[i] = NULL;
	return (paths);
}

/**
 * main - initialized an interactive shell
 *
 * Return: the corresponding output of the shell command
 */
int main(void)
{
	ssize_t read;
	char *line = NULL, *path_env, *path_token, *dup_path;
	size_t len = 0;
	pid_t child_pid;
	char *argv[64], path[1024];
	int status;

	while (1)
	{
		printf("$ ");

		read = getline(&line, &len, stdin);
		if (read == -1)
		{
			exit(EXIT_FAILURE);
			free(line);
		}
		tokenize(line, argv);

		if (argv[0] && _strcmp(argv[0], "exit") == 0)
		{
			free(line);
			exit(EXIT_SUCCESS);
		}

		if (!_strchr(argv[0], '/'))
		{
			path_env = getenv("PATH");
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
		}

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

	free(line);
	exit(EXIT_SUCCESS);
}
