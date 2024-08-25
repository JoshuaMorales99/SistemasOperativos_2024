/* --------------------------------------------------------------------------------------------
 - ENUNCIADO:
-----------------------------------------------------------------------------------------------
    Imprimir mensaje diciendo 'Hola, Operativos!!' usamdo las Commons-library

    NOTA: Para mostrar lo que retorna el programa, procedemos de la siguiente manera. En consola:
        $ make all                      (Para compilar el proyecto)
        $ ./bin/Ejercicio               (Para ejecutar el ejecutable 'Ejercicio')
-------------------------------------------------------------------------------------------- */

// Incluir las librerias necesarias.
#include <stdio.h>
#include <stdlib.h>
#include <commons/txt.h>

int main(int argc, char* argv[]) {
    // Imprimir un mensaje en la salida estandar (Funcion de la commons-library)
    txt_write_in_stdout("Hola, Operativos!!\n");

    return 0;
}
