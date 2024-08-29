#include "main.h"

int main(int argc, char **argv, char **env)
{
    char *value = _getenv("PATH");
    if (value != NULL)
	{
        printf("PATH=%s\n", value);
    }
	else
	{
        printf("Environment variable not found\n");
    }
    return 0;
}
