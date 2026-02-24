#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

#define MAXARGS 10
#define MAX_INPUT 100

int
parse(char *input, char *argv[])
{
    int argc = 0;

    while(*input){
        while(*input == ' ')
            *input++ = 0;

        if(*input == 0)
            break;

        argv[argc++] = input;

        while(*input && *input != ' ')
            input++;
    }

    argv[argc] = 0;
    return argc;
}

int
main(void)
{
    char input[MAX_INPUT];
    char *argv[MAXARGS];

    printf("\n|||bienvenido a EAFITos |||\n");

    while(1){
        printf("EAFITos> ");

        gets(input, MAX_INPUT);
        input[strlen(input)-1] = 0;

        int argc = parse(input, argv);

        if(argc == 0)
            continue;

        if(strcmp(argv[0], "salir") == 0){
            printf("saliendo...\n");
            exit(0);
        }

        if(strcmp(argv[0], "ayuda") == 0){
    printf("Comandos disponibles:\n");
    printf("  listar                - Muestra contenido del directorio actual\n");
    printf("  leer <archivo>        - muestra contenido de un archivo\n");
    printf("  tiempo                - muestra tiempo desde inicio del sistema\n");
    printf("  calc <n1> <op> <n2>   - calculadora basica\n");
    printf("  ayuda                 - muestra esta ayuda\n");
    printf("  salir                 - termina la ejecucion\n");
    printf("  directorio            - muestra la direccion del kernel\n");
    printf("  kernel                - ver informacion del kernel\n");

continue;
}

        int pid = fork();

       if(pid == 0){
    char path[50];

    path[0] = '/';
    strcpy(path + 1, argv[0]);

    exec(path, argv);

    printf("comando no reconocido\n");
    exit(0);
}
        }
    }

