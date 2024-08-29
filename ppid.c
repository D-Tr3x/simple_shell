#include "main.h"

/**
 *
 */
int _getppid(void)
{
	pid_t ppid = getppid();
	printf("%u\n", ppid);
	return (0);
}
