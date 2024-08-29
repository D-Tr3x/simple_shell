#include "main.h"

/**
 * main - initialized an interactive shell
 *
 * Return: the corresponding output of the shell command
 */
int main(void)
{
	ssize_t read;
	char *line = NULL, *token, *path_env, *path_token, *dup_path;
	size_t len = 0;
	pid_t child_pid;
	char *argv[64], path[1024];
	int i, status;

	while (1)
	{
		printf("$ ");

		read = getline(&line, &len, stdin);
		if (read == -1)
		{
			exit(EXIT_FAILURE);
			free(line);
		}

		i = 0;

		token = strtok(line, " \n");
		while (token != NULL)
		{
			argv[i++] = token;
			token = strtok(NULL, " \n");
		}
		argv[i] = NULL;

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
