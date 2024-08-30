#include "main.h"

/**
 * _getppid - prints the process ID of a current process
 *
 * Return: Always 0 (Success)
 */
int _getppid(void)
{
	pid_t ppid = getppid();

	printf("%u\n", ppid);

	return (0);
}
