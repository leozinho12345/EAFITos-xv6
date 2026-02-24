#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
    printf("Ejecutando comando kernel...\n");

    kernel();   

    exit(0);
}
