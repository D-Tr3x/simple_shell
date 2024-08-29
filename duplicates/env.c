#include "main.h"

extern char **environ;  // Declaration of the environ variable

int main(void)
{
    char **env = environ;

    // Print each environment variable
    while (*env)
    {
        printf("%s\n", *env);
        env++;
    }

    return 0;
}
