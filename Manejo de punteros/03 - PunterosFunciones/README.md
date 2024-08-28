# Punteros a Funciones
Un puntero a una función es una variable que almacena la dirección de memoria de una función, lo cual permite invocar dicha función a través del puntero. Los punteros a funciones se declaran de manera similar a otros punteros, con la diferencia de que es necesario especificar el tipo de valor que retorna y los tipos de datos de los parámetros que acepta. Esencialmente, se declara de una forma similar a la propia función a la que apuntará. Por ejemplo:

```c
void (*f)(int,int);
```

En este caso, estamos declarando un puntero `f` a una función que recibirá dos enteros como parámetros y no retornará ningún valor (`void`).

En el siguiente código, veremos un ejemplo de cómo utilizar un puntero a función:

```c
#include <stdlib.h>
#include <stdio.h>

void imprimirValor(int x) {
    printf("%d\n", x);
}

int main() {
    // Declarar un puntero a funcion que toma un entero y no retorna valor.
    void (*punteroAFuncion)(int);
    // Asignar la direccion de la funcion imprimirValor al puntero.
    punteroAFuncion = &imprimirValor;
    // Llamar a la funcion a traves del puntero.
    punteroAFuncion(1);

    return 0;
}
```

## Explicación del ejemplo:
1. Declaración de un puntero a función:

    ```c
    void (*punteroAFuncion)(int);
    ```

    Aquí declaramos `punteroAFuncion` como un puntero a una función que recibe un entero y no retorna un valor.

2. Le asignamos al puntero la dirección en memoria de la función imprimirValor.

    ```c
    punteroAFuncion = &imprimirValor;
    ```

    En este paso, asignamos al puntero `punteroAFuncion` la dirección de la función `imprimirValor`.

3. Llamada a la función mediante el puntero:

    ```c
    punteroAFuncion(1);
    ```

    Llamamos a la función `imprimirValor` a través del puntero `punteroAFuncion`. La sintaxis es idéntica a la llamada de una función ordinaria.

## Aplicación práctica: Funciones Genéricas con Punteros a Funciones
Los punteros a funciones pueden ser especialmente útiles para reutilizar código en funciones genéricas. Imaginemos que tenemos una lista de alumnos en la que se conoce su nombre, apellido, curso y las notas de cada parcial.

```c
typedef struct t_alumno {
    char *nombre;
    char *apellido;
    int  curso;
    int  notaPrimerParcial;
    int  notaSegundoParcial;
    t_alumno *siguiente;
} t_alumno;
```

En este ejemplo, el campo `siguiente` se utiliza para formar una lista enlazada de alumnos. Una operación común en listas es realizar un filtrado, es decir, obtener una sublista que cumpla con ciertas condiciones. Por ejemplo, podríamos querer obtener todos los alumnos de un curso específico o aquellos cuyo nombre comience con una letra en particular.

Supongamos que inicialmente creamos funciones como:

```c
t_alumno *filtrarPorCurso(t_alumno *listaAlumnos, int curso);
t_alumno *filtrarPorLetraInicialNombre(t_alumno *listaAlumnos, char c);
```

### Implementación de `filtrarPorCurso`
Una posible implementación de filtrarPorCurso sería:

```c
t_alumno *filtrarPorCurso(t_alumno *listaAlumnos, int curso) {
    // Declarar un puntero auxiliar para recorrer la lista.
    t_alumno *aux = listaAlumnos;
    // Declarar una nueva lista para almacenar los resultados.
    t_alumno *listaFiltrada = crearListaAlumnos();

    // Recorrer la lista auxiliar.
    while (aux != NULL) {
        // Verificar si el curso del alumno coincide con el criterio.
        if (aux->curso == curso) {
            // Agregar a la lista filtrada.
            agregarALista(listaFiltrada, aux);
        }

        // Avanzar al siguiente alumno en la lista.
        aux = aux->siguiente;
    }

    // Devolver la lista de alumnos filtrados.
    return listaFiltrada;
}
```

### Implementación de `filtrarPorLetraInicialNombre`
Una posible implementación de filtrarPorLetraInicialNombre sería:

```c
t_alumno *filtrarPorLetraInicialNombre(t_alumno *listaAlumnos, char c) {
    // Declarar un puntero auxiliar para recorrer la lista.
    t_alumno *aux = listaAlumnos;
    // Declarar una nueva lista para almacenar los resultados.
    t_alumno *listaFiltrada = crearListaAlumnos();

    // Recorrer la lista auxiliar.
    while (aux != NULL) {
        // Verificar si el nombre del alumno empieza con la letra especificada.
        if (aux->nombre[0] == c) {
            // Agregar a la lista filtrada.
            agregarALista(listaFiltrada, aux);
        }

        // Avanzar al siguiente alumno en la lista.
        aux = aux->siguiente;
    }

    // Devolver la lista de alumnos filtrados.
    return listaFiltrada;
}
```

### Generalización con Punteros a Funciones
En lugar de escribir una función de filtrado para cada criterio, podemos crear una función genérica que acepte un puntero a función como criterio de filtrado. De esta manera, podemos reutilizar el mismo código para diferentes criterios simplemente pasando diferentes funciones.

```c
t_alumno *filtrarPorCriterio(t_alumno *listaAlumnos, bool (*criterio)(t_alumno*)) {
    // Declarar un puntero auxiliar para recorrer la lista.
    t_alumno *aux = listaAlumnos;
    // Declarar una nueva lista para almacenar los resultados.
    t_alumno *listaFiltrada = crearListaAlumnos();

    // Recorrer la lista original.
    while (aux != NULL) {
        // Si el alumno cumple con el criterio de filtrado.
        if (criterio(aux)) {
            // Agregar a la lista filtrada.
            agregarALista(listaFiltrada, aux);
        }

        // Avanzar al siguiente alumno en la lista.
        aux = aux->siguiente;
    }

    // Devolver la lista de alumnos filtrados.
    return listaFiltrada;
}
```

En este ejemplo, la función `filtrarPorCriterio` toma una lista de alumnos y un puntero a función `criterio` que implementa la lógica del filtrado. Esto permite definir criterios de filtrado dinámicamente.

### Uso de la Función Genérica
```c
int main(int argc, char **argv) {
    // Letra inicial para el criterio de filtrado.
    char inicial = 'A';

    // Función criterio que verifica si el nombre de un alumno empieza con una letra específica
    bool nombreEmpiezaCon(t_alumno *alumno) {
        return alumno->nombre[0] == inicial;
    }

    // ... inicializar lista de alumnos ...

    // Filtrar alumnos cuyos nombres empiecen con 'A' usando la función genérica
    t_alumno *filtrados = filtrarPorCriterio(alumnos, nombreEmpiezaCon);

    return 0;
}
```

En este caso, `nombreEmpiezaCon` es una función que implementa el criterio de filtrado. El uso de punteros a funciones permite cambiar el criterio de manera flexible y reutilizar la misma lógica de filtrado para diferentes propósitos.

# Biblioteca
[Manejo de punteros](https://docs.utnso.com.ar/guias/programacion/punteros)