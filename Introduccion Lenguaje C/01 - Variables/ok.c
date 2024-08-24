/* --------------------------------------------------------------------------------------------
 - ENUNCIADO:
-----------------------------------------------------------------------------------------------
    Declarar una variable en C, inicializarla y asignarle otro valor.

    NOTA: Para mostrar lo que retorna el programa, procedemos de la siguiente manera. En consola:
        $ gcc ok.c -o ok                (Para compilar el programa 'ok.c' y generar el ejecutable 'ok')
        $ ./ok                          (Para ejecutar el ejecutable 'ok')
        $ echo $?                       (Para mostrar el valor de retorno del programa)
-------------------------------------------------------------------------------------------- */

int main(void) {
    // Declarar la variable de estado de salida e inicializarla.
	int exit_status = 0;
    // Asignarle otro valor a la variable de estado de salida.
    exit_status = 1;

    // Retornar el estado de salida.
	return exit_status;
}