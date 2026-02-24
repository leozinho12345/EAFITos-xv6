#EAFITos - Shell personalizada basada en xv6
EAFITos es una shell personalizada desarrollada sobre xv6-riscv, un sistema operativo educativo creado por MIT.

El proyecto está organizado siguiendo la estructura original de xv6:

xv6-riscv/
├─ kernel/      Codigo nucleo del sistema operativo
├ user/        Programas en espacio de usuario
 Makefile    Configuración de compilación
└ README.md  documentación del proyecto

### 🔹 kernel/

Contiene el núcleo del sistema operativo:

- Manejo de procesos
- Planificador (scheduler)
- Memoria virtual
- Sistema de archivos
- Llamadas al sistema (syscalls)

  Que archivos se modificaron
  
- kernel/syscall.c
- kernel/syscall.h
- kernel/sysproc.c
- kernel/param.h


#user

Contiene los programas en espacio de usuario, y aqui se encuentra la shell personalizada y los comandos implementados.

Archivos principales del proyecto
 user/eafitos.c → Shell principal
 user/ayuda.c
 user/calc.c
 user/leer.c
 user/listar.c
 user/tiempo.c
 user/kernel.c
 user/directorio.c
 user/salir.c
user/contar.c
user/usuario.c

Cada comando es un programa independiente que se ejecuta mediante fork() y exec().

---

## ⚙ Funcionamiento interno

La shell EAFITos funciona de esta forma:
se lee la entrada del usuario, despues se divide la línea en argumentos, se crea un proceso hijo con fork() luego se ejecuta el comando solicitado con exec() y el proceso padre espera con wait()

Se utilizan llamadas al sistema como:

 fork()exec()
 wait()getpid()
 uptime() open()read()
 write() sbrk()

Esto demuestra la separación entre espacio de usuario y espacio de kernel.



#Comandos implementados

| Comando | Descripción |


| listar | Muestra el contenido del directorio actual |
| leer <archivo> | Muestra el contenido de un archivo |
| calc <n1> <op> <n2> | Calculadora básica |
| tiempo | Muestra el tiempo desde el inicio del sistema |
| kernel | Muestra información del proceso y memoria |
| directorio | Muestra el directorio actual |
| contar | Cuenta líneas o elementos |
| usuario | Información del usuario |
| ayuda | Muestra la lista de comandos |
| salir | Termina la ejecución de la shell |

---
Como ejecutar el sistema:

En la terminal de UBUNTU, ubicarse en la carepta raiz del proyecto que es cd xv6-riscv
y luego make clean y make qemu
y con el comando de ayuda, podra ver la lista completa.

---

 Objetivos alcanzados

|Comprension del modelo usuario/kernel|
 immplementación de nuevos comandos en espacio de usuario
  personalización de una shell sobre un sistema operativo real
