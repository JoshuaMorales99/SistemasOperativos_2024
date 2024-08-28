# Desreferencia (`*`)
Consideremos el siguiente fragmento de código en C:

```c
#include <stdlib.h>
#include <stdio.h>

int main(void){
	int i = 1;
	int *p;

	printf("Antes i vale: %d\n", i);

	p = &i; // p apunta a i
    *p = 2; // Se le asigna a donde este    apuntando p (i) el valor 2

	printf("Ahora i vale: %d y el contenido de p vale: %d\n", i, *p);

	return 0;
}
```

Al ejecutar el código, la salida en consola será:
- Antes `i` vale 1.
- Ahora `i` vale 2 y el contenido de `p` vale 2.

Explicación paso a paso.
1. Declaramos una variable `i` de tipo `int` con un valor inicial de 1:

    ```c
    int i = 1;
    ```

2. Declaramos un puntero `p` que puede apuntar a un entero:

    ```c
    int *p;
    ```

3. Imprimimos el valor inicial de `i`, lo cual mostrará 1 en pantalla:

    ```c
    printf("Antes i vale: %d\n", i);
    ```

4. Asignamos al puntero `p` la dirección de memoria de `i` usando el operador `&`:

    ```c
    p = &i;
    ```

5. Utilizamos el operador de desreferencia `*` para asignar un nuevo valor al dato apuntado por `p`(en este caso, `i`), estableciendo su valor en 2:

    ```c
    *p = 2;
    ```

6. Finalmente, imprimimos los valores de `p` e `i` , confirmando que ambos son iguales a 2:

    ```c
    printf("Ahora i vale: %d y el contenido de p vale: %d\n", i, *p);
    ```

El resultado muestra que tanto `i` como el valor apuntado por `p` son 2, lo que significa que al modificar el contenido de la memoria apuntada por `p` , estamos también modificando el valor de `i`. Esto demuestra cómo, a través de un puntero, podemos manipular directamente el contenido de una dirección de memoria específica.

## Aplicación práctica de la desreferencia
Supongamos que queremos modificar una variable dentro de una función y que ese cambio sea visible fuera de ella. Sin el uso de punteros, cualquier modificación se haría solo sobre una copia de la variable original (esto se conoce como "pasar por valor"). Consideremos el siguiente ejemplo:

```c
#include <stdlib.h>
#include <stdio.h>

void sumarUno(int unaVariable){
    // Sumar 1 al valor de la variable.
	unaVariable = unaVariable + 1;

    // Imprimir por pantalla el valor de i.
	printf("Dentro de la funcion, i vale: %d\n", unaVariable);
}

int main(void){
	int i = 1;

    // Imprimir por pantalla el valor de i antes de ejecutar la funcion.
	printf("Antes de ejecutar la funcion, i vale: %d\n", i);
    // Llamar a la funcion sumarUno.
	sumarUno(i);
    // Imprimir por pantalla el valor de i despues de ejecutar la funcion.
	printf("Despues de ejecutar la funcion, i vale: %d\n", i);

	return 0;
}
```
La salida sería:
- Antes de ejecutar la función, `i` vale: 1.
- Dentro de la función, `i` vale: 2.
- Después de ejecutar la función, `i` vale: 1.

Este comportamiento ocurre porque en C, los argumentos se pasan por valor, es decir, se trabaja con una copia de la variable. Si deseamos que los cambios persistan fuera de la función, debemos pasar un puntero como parámetro. Así, la función puede modificar directamente el valor en la memoria de la variable original:

```c
#include <stdlib.h>
#include <stdio.h>

void sumarUno(int *unaVariable){
    // Sumar 1 al valor de la variable.
	(*unaVariable) = (*unaVariable) + 1;

    // Imprimir por pantalla el valor de i.
	printf("Dentro de la funcion, i vale: %d\n", *unaVariable);
}

int main(void){
	int i = 1;

    // Imprimir por pantalla el valor de i antes de ejecutar la funcion.
	printf("Antes de ejecutar la funcion, i vale: %d\n", i);
    // Llamar a la funcion sumarUno.
	sumarUno(&i);
    // Imprimir por pantalla el valor de i despues de ejecutar la funcion.
	printf("Despues de ejecutar la funcion, i vale: %d\n", i);

	return 0;
}
```

Ahora la salida será:
- Antes de ejecutar la función, `i` vale: 1.
- Dentro de la función, `i` vale: 2.
- Después de ejecutar la función, `i` vale: 2.

## Desreferencia en estructuras (`->`)
El operador `->` proporciona una sintaxis más conveniente para acceder a los miembros de una estructura a través de un puntero. Supongamos que tenemos la siguiente estructura`t_persona`:

```c
// Definicion de la estructura t_persona
typedef struct t_persona {
    char *nombre;
    char *apellido;
    int edad;
} t_persona;
```

Si queremos crear un puntero a una instancia de `t_persona` y asignarle valores, podríamos utilizar el operador de desreferencia `*`.

```c
t_persona *p = malloc(sizeof(t_persona));
(*p).nombre = "Esteban";
(*p).apellido = "Trabajos";
(*p).edad = 56;
```

Sin embargo, C ofrece el operador `->`("flechita") para simplificar el acceso a los miembros de la estructura a través de punteros:

```c
t_persona *p = malloc(sizeof(t_persona));
p->nombre = "Esteban";
p->apellido = "Trabajos";
p->edad = 56;
```

Este operador es especialmente útil cuando trabajamos con estructuras anidadas. Por ejemplo, si `t_persona` tiene un campo que apunta a otra `t_persona` (como un hijo), podemos acceder a sus campos utilizando `->` repetidamente:

```c
// Definicion de la estructura t_persona
typedef struct t_persona {
    char *nombre;
    char *apellido;
    int edad;
    struct t_persona* hijo;         // Puntero a otra estructura t_persona
} t_persona;

// Inicialización de los campos de la persona principal.
padre->nombre = "Esteban";
padre->apellido = "Trabajos";
padre->edad = 56;
// Inicialización de los campos del hijo.
padre->hijo->nombre = "Pedro";
padre->hijo->apellido = "Trabajos";
padre->hijo->edad = 56;
```

En este caso, `p->hijo->nombre` accede directamente al nombre del hijo de `p`.

# Bibliografía
[Manejo de punteros](https://docs.utnso.com.ar/guias/programacion/punteros)