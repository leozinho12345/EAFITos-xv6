#include "kernel/types.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
    char *args[] = { "ls", 0 };
    exec("/ls", args);

    printf("Error ejecutando ls\n");
    exit(0);
}
