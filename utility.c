#include "main.h"

void handler(int sig)
{
    if (sig == SIGQUIT)
    {
        _exit(EXIT_FAILURE);
    }
}
