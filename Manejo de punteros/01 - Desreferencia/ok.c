/* --------------------------------------------------------------------------------------------
 - ENUNCIADO:
-----------------------------------------------------------------------------------------------
    Desreferenciar una variable en C y una estructura de datos.

    NOTA: Para mostrar lo que retorna el programa, procedemos de la siguiente manera. En consola:
        $ gcc ok.c -o ok                (Para compilar el programa 'ok.c' y generar el ejecutable 'ok')
        $ ./ok                          (Para ejecutar el ejecutable 'ok')
        $ echo $?                       (Para mostrar el valor de retorno del programa)
-------------------------------------------------------------------------------------------- */

#include <stdlib.h>
#include <stdio.h>

// Definición de la estructura t_persona
typedef struct t_persona {
    char *nombre;
    char *apellido;
    int edad;
    struct t_persona* hijo;         // Puntero a otra estructura t_persona
} t_persona;

void sumarUno(int *unaVariable){
    // Sumar 1 al valor de la variable.
	(*unaVariable) = (*unaVariable) + 1;

    // Imprimir por pantalla el valor de i.
	printf("Dentro de la funcion, i vale: %d\n", *unaVariable);
}

int main(void){
    // Declarar la variable de estado de salida e inicializarla.
	int i = 1;

    // Imprimir por pantalla el valor de i antes de ejecutar la funcion.
	printf("Antes de ejecutar la funcion, i vale: %d\n", i);
    // Llamar a la funcion sumarUno.
	sumarUno(&i);
    // Imprimir por pantalla el valor de i despues de ejecutar la funcion.
	printf("Despues de ejecutar la funcion, i vale: %d\n\n", i);

    // Reservar espacio en memoria para el padre.
    t_persona *padre = malloc(sizeof(t_persona));
    // Reservar espacio en memoria para el hijo.
    padre->hijo = malloc(sizeof(t_persona));

    // Inicialización de los campos de la persona principal.
    padre->nombre = "Esteban";
    padre->apellido = "Trabajos";
    padre->edad = 56;
    // Inicialización de los campos del hijo.
    padre->hijo->nombre = "Pedro";
    padre->hijo->apellido = "Trabajos";
    padre->hijo->edad = 56;

    // Imprimir la información del padre.
    printf("Nombre del padre: %s\n", padre->nombre);
    printf("Apellido del padre: %s\n", padre->apellido);
    printf("Edad del padre: %d\n", padre->edad);
    // Imprimir la información del hijo.
    printf("Nombre del hijo: %s\n", padre->hijo->nombre);
    printf("Apellido del hijo: %s\n", padre->hijo->apellido);
    printf("Edad del hijo: %d\n", padre->hijo->edad);

    // Liberar memoria del hijo.
    free(padre->hijo);
    // Liberar memoria del padre.
    free(padre);

	return 0;
}