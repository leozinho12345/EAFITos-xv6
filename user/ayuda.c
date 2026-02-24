#include "kernel/types.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
    printf("Comandos disponibles:\n");
    printf("  listar                - Muestra contenido del directorio actual\n");
    printf("  leer <archivo>        - Muestra contenido de un archivo\n");
    printf("  tiempo                - Muestra tiempo desde inicio del sistema\n");
    printf("  calc <n1> <op> <n2>   - Calculadora basica\n");
    printf("  ayuda                 - Muestra esta ayuda\n");
    printf("  salir                 - Termina la ejecucion\n");
    printf("  directorio            - Muestra la direccion de este\n");
    printf("  kernel\n");
    printf(" eafitos                - entrar al programa de usuario eafitos\n");
    exit(0);
}
