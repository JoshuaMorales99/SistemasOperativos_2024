// Funciones basicas.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Funciones de socket.
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

// Funciones de error.
#include <errno.h>
#include <commons/error.h>

// #include <signal.h>

// ---------------------------------------------------------------------------------------------
/*
// Obtener informacion de la red.
void informacionRed(struct addrinfo hints, struct addrinfo **server_info) {
    // Þara guardar el codigo de error (Si lo hubiera)
    int err;

    // Devolver informacion de red sobre la IP y puerto.
    err = getaddrinfo("127.0.0.1", "4444", &hints, &&server_info);

    // Verificar si hubo error al obtener informacion de red.
    if(err) {
        // Imprimir por pantalla el mensaje de error.
        error_show("Error al obtener informacion de red - Socket cliente");
        // Abortar el programa.
        abort();
    }
}

// Crear socket.
int crearSocket(struct addrinfo **server_info) {
    // Crear el socket del cliente.
    int fd_conexion = socket(server_info->ai_family, server_info->ai_socktype, server_info->ai_protocol);
    // Verificar si hubo error al crear socket de escucha del servidor.
    if(fd_conexion == -1) {
        // Imprimir por pantalla el mensaje de error.
        error_show("Error al crear socket de escucha - Socket servidor");
        // Cerrar el socket de escucha del servidor.
        close(fd_conexion);
        // Abortar el programa.
        abort();
    }

    // Devolver el socket del servidor.
    return fd_conexion;
}

// Connect


// Send


// Recev


// Iniciar cliente.
int iniciarCliente() {
    // Puntero que apunta hacia los datos necesarios para la creación del socket.
    struct addrinfo hints;
	struct addrinfo *server_info;

    // Establecer el hints con 0s.
    memset(&hints, 0, sizeof(hints));
    // Especifica la familia de direcciones deseada para las direcciones devueltas.
    hints.ai_family = AF_INET;
    // Especifica el tipo de socket preferido.
    hints.ai_socktype = SOCK_STREAM;

    // Obtener informacion de red sobre la IP y puerto.
    informacionRed(hints, &server_info);
    // Crear socket de escucha del servidor.
    int fd_conexion = crearSocket(&server_info);
    // Liberar la memoria del server_info.
    freeaddrinfo(server_info);

    // Devolver el socket del cliente.
    return fd_conexion;
}
*/

// NOTA: INTENTAR HACERLO PRIMERO DIRECTAMENTE EN EL MAIN Y LUEGO IR DELEGANDO.

int main() {
    // ---------------------------------- SOCKET ----------------------------------
    // Þara guardar el codigo de error (Si lo hubiera)
    int err;
    // Puntero que apunta hacia los datos necesarios para la creación del socket.
    struct addrinfo hints, *server_info;

    // Establecer el hints con 0s.
    memset(&hints, 0, sizeof(hints));
    // Especifica la familia de direcciones deseada para las direcciones devueltas.
    hints.ai_family = AF_INET;
    // Especifica el tipo de socket preferido.
    hints.ai_socktype = SOCK_STREAM;

    // Devolver informacion de red sobre la IP y puerto.
    err = getaddrinfo("127.0.0.1", "4444", &hints, &server_info);

    // Verificar si hubo error al obtener informacion de red (Si lo hubo, err sera distinto a 0)
    if(err) {
        // Imprimir por pantalla el mensaje de error.
        error_show("Error al obtener informacion de red - Socket cliente");
        // Abortar el programa.
        abort();
    }

    // Crear el socket del cliente.
    int fd_conexion = socket(server_info->ai_family, server_info->ai_socktype, server_info->ai_protocol);
    // Verificar si hubo error al crear socket de conexion del cliente.
    if(fd_conexion == -1) {
        // Imprimir por pantalla el mensaje de error.
        error_show("Error al crear socket de conexion - Socket cliente");
        // Cerrar el socket de conexion del cliente.
        close(fd_conexion);
        // Abortar el programa.
        abort();
    }

    // ---------------------------------- CONNECT ----------------------------------
    // Conectar el cliente con el socket servidor.
    err = connect(fd_conexion, server_info->ai_addr, server_info->ai_addrlen);
    // Verificar si hubo error al conectar el cliente con el socket servidor.
    if(err == -1) {
        // Imprimir por pantalla el mensaje de error.
        error_show("Error al conectar el cliente con el socket servidor - Socket cliente");
        // Cerrar el socket de conexion del cliente.
        close(fd_conexion);
        // Abortar el programa.
        abort();
    }

    // Liberar la memoria del server_info.
    freeaddrinfo(server_info);

    // ---------------------------------- SEND ----------------------------------
    // Cantidad de bytes enviados y/o recibidos.
    size_t bytes;

    // Entero a enviar.
    int32_t handshake = 1;
    // Para guardar la respuesta del servidor.
    int32_t result;

    // Enviar un entero al servidor.
    bytes = send(fd_conexion, &handshake, sizeof(int32_t), 0);
    // Verificar si hubo error al enviar un entero al servidor.
    if(bytes == -1) {
        // Imprimir por pantalla el mensaje de error.
        error_show("Error al enviar un entero al servidor - Socket cliente");
        // Cerrar el socket de conexion del cliente.
        close(fd_conexion);
        // Abortar el programa.
        abort();
    }

    // Imprimir mensaje de estado enviado.
    printf("Entero enviado correctamente\n");

    // ---------------------------------- RECV ----------------------------------
    // Recibir la respuesta del servidor.
    bytes = recv(fd_conexion, &result, sizeof(int32_t), MSG_WAITALL);
    // Verificar si hubo error al recibir respuesta del servidor.
    if(bytes == -1) {
        // Imprimir por pantalla el mensaje de error.
        error_show("Error al recibir la respuesta del servidor - Socket cliente");
        // Cerrar el socket de conexion del cliente.
        close(fd_conexion);
        // Abortar el programa.
        abort();
    }

    // Imprimir mensaje de estado recibido.
    printf("Se recibio correctamente respuesta del servidor\n");

    // Verificar respuesta del servidor.
    if(result == 0) {
        // Imprimir mensaje de satisfaccion.
        printf("El entero fue recibido correctamente\n");
    } else {
        // Imprimir mensaje de insatisfaccion.
        printf("El entero no fue recibido correctamente\n");
    }

    // Cerrar el socket de conexion del cliente.
    close(fd_conexion);

    return 0;
}