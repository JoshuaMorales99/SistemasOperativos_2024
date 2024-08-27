/* --------------------------------------------------------------------------------------------
 - ENUNCIADO:
-----------------------------------------------------------------------------------------------
    Reservar memoria en C, inicializar un valor y liberar la memoria.

    NOTA: Para mostrar lo que retorna el programa, procedemos de la siguiente manera. En consola:
        $ gcc ok.c -o ok                (Para compilar el programa 'ok.c' y generar el ejecutable 'ok')
        $ ./ok                          (Para ejecutar el ejecutable 'ok')
        $ echo $?                       (Para mostrar el valor de retorno del programa)
-------------------------------------------------------------------------------------------- */

#include <stdlib.h>
#include <stdio.h>

int main(void) {
    // Reservar espacio en memoria de tamanio equivalente a la cantidad de bytes de un entero.
    int *p = malloc(sizeof(int));
    // Asignar valor inicial al dato contenido en el espacio en memoria.
    *p = 2;

    // Imprimir por pantalla el valor de la variable.
    printf("p = %d\n", *p);
    // Imprimir por pantalla la dirección de memoria de la variable.
    printf("&p = %p\n", &p);

    // Liberar espacio en memoria.
    free(p);

    return 0;
}