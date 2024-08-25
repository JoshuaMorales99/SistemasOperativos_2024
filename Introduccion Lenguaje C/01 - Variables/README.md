# Variables
En el ejemplo anterior, escribimos, compilamos y ejecutamos nuestro primer programa en C. Sin embargo, ese programa era bastante básico. Ahora, vamos a introducir un concepto fundamental en programación: las variables.

## Introducción
A continuación, modificamos nuestro programa para incluir una variable:
```c
int main(void) {
	int exit_status = 0;
	return exit_status;
}
```

En esta versión del programa, hemos introducido una variable llamada `exit_status`. Veamos qué ha cambiado:

1. Ahora tenemos dos instrucciones dentro de la función `main()`. En lugar de return 0;, utilizamos return `exit_status;`.
2. Hemos declarado una variable exit_status de tipo `int` y la hemos inicializado con el valor 0.

¿Qué es una Variable?
En C, una variable es un identificador que apunta a un espacio en memoria donde se puede almacenar un valor. Antes de utilizar una variable, es necesario declararla, indicando:

1. Que la variable existe.
2. El tipo de datos que puede almacenar.

En nuestro caso, la declaración `int exit_status = 0;` crea una variable de tipo entero (`int`) llamada `exit_status` e inicializa su valor en 0.

## Declaración de Variables
Para declarar una variable, se especifica su tipo seguido del nombre de la variable. Por ejemplo:

- `int hola;` declara una variable llamada `hola` de tipo entero.
- `int hola, chau;` declara dos variables, `hola` y `chau`, ambas de tipo entero.

## Asignación de Valores
Una vez que se ha declarado una variable, podemos asignarle un valor utilizando el operador de asignación `=`. Por ejemplo, en la instrucción `int exit_status = 0;`, estamos inicializando la variable `exit_status` con el valor 0.

## Nombres de Variables
Es importante elegir nombres de variables que sean descriptivos y representen claramente su propósito. En nuestro ejemplo, `exit_status` es un nombre que sugiere que la variable almacenará el estado de salida del programa. Aunque podríamos utilizar nombres menos significativos como `a`, `bleh`, o incluso `__a256723b`, es una buena práctica elegir nombres que faciliten la comprensión del código.

## Ejecución del Programa
Probemos nuestro programa modificado:

```bash
$ gcc ok.c -o ok
$ ./ok
$ echo $?
0
```

Al compilar y ejecutar el programa, y luego utilizar `echo $?`, obtenemos el valor 0, que es el estado de salida que hemos definido con la variable `exit_status`.

## Modificando el Valor de la Variable
Para demostrar que `exit_status` no es una "variable mágica" de C, sino una variable común, cambiemos su valor:

```c
int main(void) {
	int exit_status = 1;
	return exit_status;
}
```

Al compilar y ejecutar nuevamente:

```bash
$ gcc ok.c -o ok
$ ./ok
$ echo $?
1
```

El valor de `exit_status` ha sido modificado a 1, lo cual se refleja en el estado de salida del programa.

## ¿Por qué usar Variables?
Las variables permiten almacenar y manipular datos de manera flexible durante la ejecución de un programa. A diferencia de los valores constantes, las variables pueden cambiar su valor:

```c
int main(void) {
	int exit_status = 0;
	exit_status = 1;
	return exit_status;
}
```

En este ejemplo, `exit_status` se inicializa en 0 y luego se asigna el valor 1. Al ejecutar:

```bash
$ gcc ok.c -o ok
$ ./ok
$ echo $?
1
```

El valor final de `exit_status` es 1, ya que el operador de asignación `=` sobrescribe el valor anterior.

## Ejemplo Adicional: Asignación y Evaluación de Variables
Vamos a explorar más:

```c
int main(void) {
	int exit_status = 0;
	int a_number = 1;
	exit_status = a_number;
	a_number = 3;
	return exit_status;
}
```

```bash
$ gcc ok.c -o ok
$ ./ok
$ echo $?
1
```

En este caso, `exit_status` toma el valor de `a_number` en el momento de la asignación, que es 1. Cambiar `a_number` después no afecta a `exit_status` porque la asignación ya se ha realizado. Esto demuestra que la relación entre las variables se evalúa en el momento de la asignación y no mantiene un vínculo permanente entre ellas.

# Biblioteca
[Introducción al Lenguaje C](https://docs.utnso.com.ar/primeros-pasos/lenguaje-c)