#include "kernel/types.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
    int pid = getpid();

    printf("Informacion del proceso actual:\n");
    printf("PID: %d\n", pid);

    exit(0);
}
