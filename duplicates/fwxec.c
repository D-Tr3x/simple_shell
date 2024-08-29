#include "main.h"

/**
 *
 */
int main(void)
{
	pid_t child_pid;
	int status;
	int i = 0;
	
	while (i < 5)
	{
		child_pid = fork();

		if (child_pid == -1)
		{
			perror("Error ");
			return (1);
		}
		
		if (child_pid == 0) //current process
		{
			char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};

			if (execve(argv[0], argv, NULL) == -1)
			{
				perror("Error");
				exit(EXIT_FAILURE);
			}
			exit(EXIT_SUCCESS);
		}

		wait(&status);
		printf("Child process (%u) now complete\n", child_pid);
		i++;
	}

	return (0);
}
