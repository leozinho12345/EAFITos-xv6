#include "kernel/types.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
    int ticks = uptime();

    printf("Tiempo desde que xv6 inicio:\n");
    printf("Ticks: %d\n", ticks);
    printf("Segundos aproximados: %d\n", ticks / 100);

    exit(0);
}
