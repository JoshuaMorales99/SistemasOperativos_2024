/* --------------------------------------------------------------------------------------------
 - ENUNCIADO:
-----------------------------------------------------------------------------------------------
    Imprimir un valor entero recibido como parametro haciendo uso de un puntero a función en C.

    NOTA: Para mostrar lo que retorna el programa, procedemos de la siguiente manera. En consola:
        $ gcc ok.c -o ok                (Para compilar el programa 'ok.c' y generar el ejecutable 'ok')
        $ ./ok                          (Para ejecutar el ejecutable 'ok')
        $ echo $?                       (Para mostrar el valor de retorno del programa)
-------------------------------------------------------------------------------------------- */

#include <stdlib.h>
#include <stdio.h>

void imprimirValor(int x) {
    // Imprimir el valor entero recibido como parametro.
    printf("%d\n", x);
}

int main() {
    // Declarar un puntero a una funcion que recibe un entero y no retorna ningun valor.
    void (*punteroAFuncion)(int);
    
    // Asignar un puntero a la direccion de la funcion imprimirValor.
    punteroAFuncion = &imprimirValor;
    // Llamar a la funcion a traves del puntero, pasando el valor 1 como argumento.
    punteroAFuncion(1);
    
    return 0;
}