#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/fcntl.h"

int
main(int argc, char *argv[])
{
    int fd;
    char buf[512];
    int n;

    if(argc < 2){
        fprintf(2, "uso: leer <archivo>\n");
        exit(1);
    }

    fd = open(argv[1], O_RDONLY);

    if(fd < 0){
        fprintf(2, "leer: no se pudo abrir %s\n", argv[1]);
        exit(1);
    }

    while((n = read(fd, buf, sizeof(buf))) > 0){
        write(1, buf, n);
    }

    close(fd);
    exit(0);
}
