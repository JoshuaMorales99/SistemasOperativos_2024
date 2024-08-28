/* --------------------------------------------------------------------------------------------
 - ENUNCIADO:
-----------------------------------------------------------------------------------------------
    Desreferenciar una variable en C y una estructura de datos.

    NOTA: Para mostrar lo que retorna el programa, procedemos de la siguiente manera. En consola:
        $ gcc ok.c -o ok                (Para compilar el programa 'ok.c' y generar el ejecutable 'ok')
        $ ./ok                          (Para ejecutar el ejecutable 'ok')
        $ echo $?                       (Para mostrar el valor de retorno del programa)
-------------------------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* copiar(char* palabra) {
    // Reservar espacio en memoria suficiente para almacenar una copia de la cadena.
    char* tmp = malloc(sizeof(char) * (strlen(palabra) + 1));

    // Verificar si la asignacion de memoria fue erronea.
    if (tmp == NULL) return NULL;

    // Copiar el contenido de la cadena original en el espacio de memoria recién reservado.
    memcpy(tmp, palabra, strlen(palabra));
    // Anidar el terminador nulo '\0' al final de la cadena copiada.
    tmp[strlen(palabra)] = '\0';

    return tmp;
}

int main() {
    // Llamar a la función copiar para crear una copia de "Hola Mundo"
    char* copia = copiar("Hola Mundo");

    // Verificar si la copia fue exitosa.
    if (copia != NULL) {
        // Imprimir la cadena copiada en consola.
        printf("%s\n", copia);
        // Liberar la memoria asignada para la copia de la cadena.
        free(copia);
    } else {
        // Imprimir mensaje de error.
        printf("Error al asignar memoria.\n");
    }

    return 0;
}