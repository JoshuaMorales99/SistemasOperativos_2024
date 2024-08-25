# Arrancando
## Introducción
Vamos a hacer un programa en C, empezando por una función simple:

```c
int main(void) {
  return 0;
}
```

Este es (aproximadamente) el programa más pequeño que podemos hacer en C. `main()` es la función que se ejecuta al iniciar un programa en C. En este caso, el prototipo de la función es `int main(void)`. Esto indica que nuestro programa no recibirá parámetros (`void`) y devolverá un entero con signo (`int`) al sistema operativo..

Nuestro programa tiene una única instrucción: devolver (`return`) 0, un código de salida que, por convención, indica que el programa se ejecutó correctamente.

Guardemos este código en un archivo llamado `ok.c` y compilemos nuestro programa:

```bash
$ gcc ok.c -o ok
$ ls
ok.c ok
```

## Compilando el programa
`gcc` es uno de los compiladores de C más utilizados, parte de la GNU Compiler Collection. Originalmente llamado GNU C Compiler, `gcc` ahora soporta también otros lenguajes como C++ y Java. Para obtener más información sobre `gcc`, podemos consultar su manual ejecutando `man gcc` en la terminal.

El comando anterior, `gcc` recibe el archivo fuente `ok.c`como argumento y el parámetro `-o` para especificar el nombre del binario resultante (`ok`). Si no especificamos un nombre con `-o`, `gcc` usará el nombre predeterminado `a.out`.

## Ejecutando el programa
Para ejecutar nuestro programa, usamos:

```bash
$ ./ok
$ echo $?
0
```

La salida `0` indica que el programa se ejecutó sin errores. ¿Qué pasó aquí?

En sistemas UNIX, para ejecutar un programa, escribimos su ruta completa seguida de los parámetros, si los hay. Por ejemplo:

```bash
$ /bin/ps --version
procps-ng version 3.3.3
```

Esto ejecuta el programa `/bin/ps` con el parámetro `--version`, mostrando la versión instalada de `ps`. En nuestro caso, ejecutamos `./ok`, donde `.` se refiere al directorio actual.

## Explicación de los comandos
En todos los directorios de UNIX existen dos enlaces especiales: `.` y `..`
- `.` hace referencia al directorio actual
- `..` al directorio padre.

Por lo tanto, `./ok` se traduce a la ruta completa de nuestro programa en el directorio actual.

### ¿Por qué no se muestra nada?
Nuestro programa no muestra nada en pantalla porque no le hemos indicado que lo haga. Solo devuelve un código de salida. Para ver el código de salida, utilizamos el comando `echo $?`.

### Uso de echo y variables en bash
El comando `echo` imprime en pantalla lo que se le pasa como argumento. El `bash` es el intérprete de comandos de nuestra consola, que utiliza variables. Para leerlas debemos anteponer un `$` al nombre de la variable:

Por ejemplo, `echo Hola mundo` imprime `Hola mundo`

```bash
$ nombre = "Mundo" # Asignar "Mundo" a la variable nombre, creandola si no existe.
$ echo $nombre # Imprimir el contenido de la variable llamada nombre.
Mundo
$ echo "Hola $nombre"
Hola Mundo
```

> `#` es el caracter de comentario.

En particular, `?` es una variable especial en `bash` que almacena el código de salida del último comando ejecutado. Al ejecutar `echo $?`, imprimimos el código de salida del programa `./ok`, que es 0.

# Biblioteca
[Introducción al Lenguaje C](https://docs.utnso.com.ar/primeros-pasos/lenguaje-c)