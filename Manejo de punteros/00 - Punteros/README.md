# Punteros
## ¿Qué es un puntero?
Un puntero es una variable que almacena la dirección de memoria de otro dato. Es importante destacar que un puntero no contiene el dato en sí mismo, sino su ubicación en la memoria, también conocida como referencia a memoria.


## ¿Cómo declaramos un puntero?
Para declarar un puntero a un tipo de dato específico, se utiliza el operador `*` delante del nombre del puntero. Por ejemplo, para declarar un puntero a un entero (`int`), se puede escribir:

```c
int *p;
```

En este caso, `p` es un puntero que puede almacenar la dirección de memoria de una variable de tipo `int`. Sin embargo, aunque el puntero ha sido declarado, aún no ha sido inicializado y, por lo tanto, apunta a una dirección de memoria indeterminada.

## ¿Cómo inicializamos un puntero? (Malloc)
La memoria puede ser reservada y liberada dinámicamente según las necesidades del programa. Para gestionar la memoria dinámica, C proporciona funciones estándar disponibles en la biblioteca `stdlib.h`.

Una de estas funciones es `malloc`(memory allocation), que solicita un bloque de memoria del tamaño especificado en bytes y devuelve un puntero a la dirección de inicio de ese bloque de memoria:

```c
void* malloc (unsigned numero_de_bytes);
```

La función `malloc` garantiza que el bloque de memoria asignado no esté siendo utilizado por otras variables en el programa. Si `malloc` no puede asignar la memoria solicitada, devuelve un puntero `NULL`, indicando que la operación ha fallado. Por esta razón, es recomendable comprobar siempre el valor de retorno de `malloc` para evitar errores de memoria.

Para inicializar un puntero que apunte a un entero, primero necesitamos reservar suficiente espacio en memoria. En sistemas comunes, un entero ocupa 4 bytes, por lo que la llamada a `malloc` sería:

```c
malloc (4);
```

Sin embargo, para evitar depender de un tamaño fijo, podemos utilizar el operador `sizeof` para determinar el tamaño exacto del tipo de dato en tiempo de ejecución:

```c
malloc(sizeof(int));
```

Esta forma de llamar a `malloc`  es preferible, ya que es más legible y mantiene el código adaptable a diferentes sistemas y tamaños de tipos de datos.

A continuación, asignamos el resultado de `malloc` al puntero:

```c
int *p = malloc(sizeof(int));
```

En resumen, un ejemplo de código inicial con un puntero se vería así:

```c
#include <stdlib.h>

int main(void){
    // Reservar espacio en memoria de tamanio equivalente a la cantidad de bytes de un entero.
    int *p = malloc(sizeof(int));

    return 0;
}
```

## Asignación de un valor a la memoria apuntada
Aunque hemos reservado espacio en memoria, no hemos inicializado el valor en esa dirección. Para asignar un valor al espacio de memoria apuntado por el puntero, utilizamos el operador de desreferencia `*` (asterisco):

```c
#include <stdlib.h>
int main(void){
    // Reservar espacio en memoria de tamanio equivalente a la cantidad de bytes de un entero.
    int *p = malloc(sizeof(int));
    // Asignar valor inicial al dato contenido en el espacio en memoria.
    *p = 2;

    return 0;
}
```
En este ejemplo, `*p = 2;` asigna el valor 2 al espacio de memoria apuntado por `*p`. Si en cambio utilizáramos `p = 2;`, estaríamos modificando la dirección almacenada en el puntero, no el valor en la memoria a la que apunta.

## Operaciones de punteros
### Obtener la dirección de una variable (`&`)
El operador `&` (ampersand) se utiliza para obtener la dirección de memoria de una variable. Este operador es útil para inicializar punteros con la dirección de variables existentes.

Podemos ilustrar su uso con el siguiente código:

```c
#include <stdlib.h>
#include <stdio.h>

int main(void){
    int *p = malloc(sizeof(int));
    *p = 1;

    // Imprimir por pantalla el valor de la variable.
    printf("p = %d\n", p);
    // Imprimir por pantalla la dirección de memoria de la variable.
    printf("&p = %p\n", &p);

    return 0;
}
```

En este código, `%d` es un especificador de formato que indica la impresión de un valor entero, mientras que `%p` se utiliza para imprimir la dirección de memoria.

> Ojo! El operador `&` se puede usar con todo tipo de variables ya que todo está contenido en la memoria.

## Problemas de gestión de memoria: "Memory Leaks"
Un problema común al trabajar con memoria dinámica es el *memory leak* o fuga de memoria. Esto ocurre cuando un programa reserva memoria (por ejemplo, con `malloc`) pero no la libera después de que ya no es necesaria. Si un programa sigue reservando memoria sin liberarla, eventualmente puede agotar la memoria disponible, afectando el rendimiento del sistema y causando que el sistema operativo termine el proceso.

Para evitar fugas de memoria, es esencial liberar la memoria asignada dinámicamente una vez que ya no se necesita, utilizando la función:
```c
free(unPuntero);
```

Ejemplo de gestión de memoria dinámica:

```c
#include <stdlib.h>
char* reservarMemoria(int n){
    // Retornar la direccion de memoria reservada.
    return malloc(n*sizeof(char));
}

int main(void){
    char* array;

    // Reservar 3 char consecutivos.
    array = reservarMemoria(3); 

    // Liberar espacio en memoria.
    free(array);
}
```

La regla de oro en la gestión de memoria dinámica es que cada llamada a `malloc` debe tener una llamada correspondiente a `free()`.

## Otros métodos de asignación de memoria
Además de `malloc`, existen otras funciones en C para la asignación de memoria dinámica:

- `calloc(n, bytes)`: Reserva memoria para un array de `n` elementos, cada uno de `bytes` tamaño, e inicializa todos los bytes a `0`. Por ejemplo, para reservar memoria para un array de 5 enteros, se utilizaría:

    ```c
    int *arrayEnteros = calloc(5, sizeof(int));
    ```

    El uso de `calloc` asegura que la memoria asignada esté inicializada a cero, lo cual no ocurre con `malloc`.

- `malloc(bytes)`: Reserva un bloque de memoria de `bytes` tamaño, pero no inicializa los bytes. El equivalente con `malloc` sería:

    ```c
    int *arrayEnteros = malloc(5 * sizeof(int));
    ```

- `realloc(*unPuntero, bytes)`: Ajusta el tamaño del bloque de memoria al que apunta `unPuntero` a un nuevo tamaño de `bytes`. Devuelve un puntero al bloque con el tamaño indicado. Es importante destacar que `realloc` intenta preservar los datos en el nuevo bloque siempre que el tamaño sea mayor o igual al original. Sin embargo, los bytes adicionales no están inicializados. Hay que tener en cuenta los siguientes casos especiales:
    - Si `unPuntero` es `NULL`, `realloc` se comporta como `malloc(bytes)`.
    - Si `unPuntero` no es `NULL` y `bytes` es `0`, `realloc` se comporta como `free(unPuntero)`.

# Bibliografía
[Manejo de punteros](https://docs.utnso.com.ar/guias/programacion/punteros)