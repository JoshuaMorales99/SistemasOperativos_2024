# Funciones que retornan punteros
Como se ha discutido anteriormente, pasar punteros como argumentos a una función resulta muy útil cuando se desea modificar el contenido de una variable dentro de la función, o para evitar la duplicación innecesaria de datos. Ahora bien, ¿qué sucede con las funciones que devuelven punteros? A continuación, se presenta un ejemplo ilustrativo:

```c
char* copiar(char* palabra) {
    // Reservar espacio en memoria suficiente para almacenar una copia de la cadena.
    char* tmp = malloc(sizeof(char) * (strlen(palabra) + 1));

    // Copiar el contenido de la cadena original en el espacio de memoria recién reservado.
    memcpy(tmp, palabra, strlen(palabra));
    // Anidar el terminador nulo '\0' al final de la cadena copiada.
    tmp[strlen(palabra)] = '\0';

    return tmp;
}
```

Esta función, si bien es simple, permite entender la utilidad de retornar punteros desde una función. Analicemos su funcionamiento en detalle:
- La función recibe un puntero a un string (`char*`) como argumento y devuelve un puntero a una nueva ubicación en memoria que contiene una copia de la cadena de caracteres original.
- Primero, se reserva espacio en memoria suficiente para almacenar una copia de la cadena. La cantidad de memoria reservada es igual a la longitud de la cadena más uno, para incluir el terminador nulo (`\0`) característico de las cadenas de caracteres en C:

    ```c
    malloc(sizeof(char) * (strlen(palabra) + 1));
    ```

- El puntero a esta nueva ubicación en memoria se asigna a la variable temporal `tmp`:

    ```c
    char* tmp =
    ```
- Luego, se copia el contenido de la cadena original en el espacio de memoria recién reservado utilizando la función `memcpy`, que se encarga de copiar un número específico de bytes de una ubicación a otra:

    ```c
    memcpy(tmp, palabra, strlen(palabra));
    ```

- A continuación, se añade el terminador nulo `\0` al final de la cadena copiada para asegurar que se trata de una cadena de caracteres válida en C:

    ```c
    tmp[strlen(palabra)] = '\0';
    ```

- Finalmente, la función retorna el puntero que apunta al comienzo de la copia de la cadena, almacenada en el nuevo segmento de memoria:

    ```c
    return tmp;
    ```

Es fundamental destacar que la memoria para la copia de la cadena se asigna dentro de la función, y, por lo tanto, cada vez que se invoque esta función, se creará un nuevo segmento de memoria para la copia de la palabra. Esto implica que el llamador de la función es responsable de liberar la memoria asignada cuando ya no sea necesaria, para evitar fugas de memoria. Este manejo se podría realizar de la siguiente manera:

```c
char* copia = copiar("Hola Mundo");

// ... uso de 'copia' ...

// Liberar la memoria después de su uso.
free(copia);
```

También es importante resaltar la verificación de la asignación de memoria. En la implementación de la función copiar, se comprueba si `malloc` ha devuelto `NULL`, lo que indicaría un fallo en la asignación de memoria. En tal caso, la función retorna `NULL`, permitiendo al código llamador manejar adecuadamente la situación de error:

```c
char* copiar(char* palabra) {
    // Reservar espacio en memoria suficiente para almacenar una copia de la cadena.
    char* tmp = malloc(sizeof(char) * (strlen(palabra) + 1));

    // Verificar si la asignacion de memoria fue erronea.
    if(tmp == NULL) return NULL;

    // Copiar el contenido de la cadena original en el espacio de memoria recién reservado.
    memcpy(tmp, palabra, strlen(palabra));
    // Anidar el terminador nulo '\0' al final de la cadena copiada.
    tmp[strlen(palabra)] = '\0';

    return tmp;
}
```

# Bibliografía
[Manejo de punteros](https://docs.utnso.com.ar/guias/programacion/punteros)