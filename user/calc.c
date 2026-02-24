#include "kernel/types.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
    if (argc != 4) {
        printf("uso: calc <num1> <operador> <num2>\n");
        exit(0);
    }

    int num1 = atoi(argv[1]);
    int num2 = atoi(argv[3]);
    char op = argv[2][0];
    int resultado;

    if (op == '+') {
        resultado = num1 + num2;
    } else if (op == '-'){
    resultado = num1 - num2;
    } else if (op == '*') {
  resultado = num1 * num2;
    } else if (op == '/') {
        if (num2 == 0) {
            printf("rror: division por cero\n");
            exit(0);
        }
        resultado = num1 / num2;
    } else {
        printf("operador invalido\n");
        exit(0);
    }

    printf("Resultado: %d\n", resultado);
    exit(0);
}
