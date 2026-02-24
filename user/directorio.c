#include "kernel/types.h"
#include "user/user.h"




int
main(int argc, char *argv[])
{
 char *args[] = { "pwd", 0 };
 exec("/pwd", args);

    printf("error ejecutando pwd\n");
    exit(0);
}
//  guayaba
