#include "main.h"
#include <stdio.h>

/**
 *
 */
void get_args(int argc, char *argv[])
{
	int i;

	for (i = 1; i < argc; i++)
	{
		printf("%s ", argv[i]);
	}
	printf("\n");

}
