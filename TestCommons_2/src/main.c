/* --------------------------------------------------------------------------------------------
 - ENUNCIADO:
-----------------------------------------------------------------------------------------------
    Imprimir mensaje diciendo '!!!Hello World!!!' usamdo las Commons-library

    NOTA: Para mostrar lo que retorna el programa, procedemos de la siguiente manera. En consola:
        $ make all                      (Para compilar el proyecto)
        $ ./bin/TestCommons_2           (Para ejecutar el ejecutable 'TestCommons_2')
-------------------------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include <commons/string.h>
#include <commons/txt.h>

int main(void) {
    // Crear un string vacio, y asignarlo a la variable declarada 'unString' (Funcion de la commons-library)
	char * unString = string_new();

    // Agrega al primer string el segundo (Funcion de la commons-library)
	string_append(&unString, "!!!Hello World!!!\n");
	// Imprimir un mensaje en la salida estandar (Funcion de la commons-library)
    txt_write_in_stdout(unString);

	return EXIT_SUCCESS;
}