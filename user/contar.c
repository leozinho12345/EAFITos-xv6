#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/fcntl.h"

int
main(int argc, char *argv[])
{
    int fd, n, i;
    char buf[512];

    int lineas = 0;
    int palabras = 0;
    int caracteres = 0;
    int en_palabra = 0;

    if(argc < 2){
        fprintf(2, "Uso: contar <archivo>\n");
        exit(1);
    }

    fd = open(argv[1], O_RDONLY);
    if(fd < 0){
        fprintf(2, "contar: no se pudo abrir %s\n", argv[1]);
        exit(1);
    }

    while((n = read(fd, buf, sizeof(buf))) > 0){
        for(i = 0; i < n; i++){
            caracteres++;

            if(buf[i] == '\n')
                lineas++;

            if(buf[i]==' ' || buf[i]=='\n' || buf[i]=='\t'){
                en_palabra = 0;
            } else if(!en_palabra){
                palabras++;
                en_palabra = 1;
            }
        }
    }

    close(fd);

    printf("Lineas: %d\n", lineas);
    printf("Palabras: %d\n", palabras);
    printf("Caracteres: %d\n", caracteres);

    exit(0);
}
