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

// #include <commons/log.h>
// #include <commons/collections/list.h>
// #include <assert.h>

// ---------------------------------------------------------------------------------------------

/*
// Obtener informacion de la red.
void informacionRed(struct addrinfo *hints, struct addrinfo **server_info) {
    // Para guardar el codigo de error (Si lo hubiera)
    int err;

    // Devolver informacion de red sobre la IP y puerto.
    err = getaddrinfo(NULL, "4444", &hints, &server_info);
    // Verificar si hubo error al obtener informacion de red.
    if(err) {
        // Imprimir por pantalla el mensaje de error.
        error_show("Error al obtener informacion de red - Socket servidor");
        // Abortar el programa.
        abort();
    }
}

// Crear socket.
int crearSocket(struct addrinfo **server_info) {
    // Crear socket de escucha del servidor.
    int fd_escucha = socket(server_info->ai_family, server_info->ai_socktype, server_info->ai_protocol);
    // Verificar si hubo error al crear socket de escucha del servidor.
    if(fd_escucha == -1) {
        // Imprimir por pantalla el mensaje de error.
        error_show("Error al crear socket de escucha - Socket servidor");
        // Cerrar el socket de escucha del servidor.
        close(fd_escucha);
        // Abortar el programa.
        abort();
    }

    // Devolver el socket del servidor.
    return fd_escucha;
}

// Asociar socket.
void asociarSocket(int *fd_escucha, struct addrinfo **server_info) {
    // Para guardar el codigo de error (Si lo hubiera)
    int err;

    // Permitir que varios sockets se puedan bindear a un puerto al mismo tiempo (Siempre y cuando pertenezcan al mismo usuario)
    err = setsockopt(fd_escucha, SOL_SOCKET, SO_REUSEPORT, &(int){1}, sizeof(int));
    // Verificar si hubo error al permitir que varios sockets se bindeen a un puerto.
    if(err) {
        // Imprimir por pantalla el mensaje de error.
        error_show("Error al permitir que varios sockets se bindeen a un puerto - Socket servidor");
        // Cerrar el socket de escucha del servidor.
        close(fd_escucha);
        // Abortar el programa.
        abort();
    }

    // Asociar el socket a un puerto.
    err = bind(fd_escucha, server_info->ai_addr, server_info->ai_addrlen);
    // Verificar si hubo error al asociar el socket a un puerto.
    if(err == -1) {
        // Imprimir por pantalla el mensaje de error.
        error_show("Error al asociar el socket a un puerto - Socket servidor");
        // Cerrar el socket de escucha del servidor.
        close(fd_escucha);
        // Abortar el programa.
        abort();
    }
}

// Escuchar socket.
void escucharSocket(int *fd_escucha) {
    // Para guardar el codigo de error (Si lo hubiera)
    int err;

    // Referenciar al socket que se utilizará para aceptar solicitudes de conexión entrantes.
    err = listen(fd_escucha, SOMAXCONN);
    // Verificar si hubo error al referenciar el socket.
    if(err) {
        // Imprimir por pantalla el mensaje de error.
        error_show("Error al referenciar el socket - Socket servidor");
        // Cerrar el socket de escucha del servidor.
        close(fd_escucha);
        // Abortar el programa.
        abort();
    }
}

// Accept


// Recev


// Send


// Iniciar servidor.
int iniciarServidor() {
    // Datos necesarios para la creacion del socket.
    struct addrinfo hints;
    struct addrinfo *server_info;

    // Establecer el hints con 0s.
    memset(&hints, 0, sizeof(hints));
    // Especifica la familia de direcciones deseada para las direcciones devueltas.
    hints.ai_family = AF_INET;
    // Especifica el tipo de socket preferido.
    hints.ai_socktype = SOCK_STREAM;
    // Especifica opciones adicionales (Al usar AI_PASSIVE se establece un socket escucha)
    hints.ai_flags = AI_PASSIVE;

    // Obtener informacion de red sobre la IP y puerto.
    informacionRed(&hints, &server_info);
    // Crear socket de escucha del servidor.
    int fd_escucha = crearSocket(&server_info);
    // Asociar socket a un puerto.
    asociarSocket(&fd_escucha, &server_info);
    // Escuchar las conexiones entrantes.
    escucharSocket(&fd_escucha);

    // Liberar la memoria del serverinfo.
    freeaddrinfo(server_info);

    // Devolver el socket del servidor.
    return fd_escucha;
}
*/

// NOTA: INTENTAR HACERLO PRIMERO DIRECTAMENTE EN EL MAIN Y LUEGO IR DELEGANDO.

int main() {
    // ---------------------------------- SOCKET ----------------------------------
    // Para guardar el codigo de error (Si lo hubiera)
    int err;

    // Datos necesarios para la creacion del socket.
    struct addrinfo hints, *server_info;

    // Establecer el hints con 0s.
    memset(&hints, 0, sizeof(hints));
    // Especifica la familia de direcciones deseada para las direcciones devueltas.
    hints.ai_family = AF_INET;
    // Especifica el tipo de socket preferido.
    hints.ai_socktype = SOCK_STREAM;
    // Especifica opciones adicionales (Al usar AI_PASSIVE se establece un socket escucha)
    hints.ai_flags = AI_PASSIVE;
    
    // Devolver informacion de red sobre la IP y puerto.
    err = getaddrinfo(NULL, "4444", &hints, &server_info);
    // Verificar si hubo error al obtener informacion de red (Si lo hubo, err sera distinto a 0)
    if(err) {
        // Imprimir por pantalla el mensaje de error.
        error_show("Error al obtener informacion de red - Socket servidor");
        // Abortar el programa.
        abort();
    }

    // Crear socket de escucha del servidor.
    int fd_escucha = socket(server_info->ai_family, server_info->ai_socktype, server_info->ai_protocol);
    // Verificar si hubo error al crear socket de escucha del servidor.
    if(fd_escucha == -1) {
        // Imprimir por pantalla el mensaje de error.
        error_show("Error al crear socket de escucha - Socket servidor");
        // Cerrar el socket de escucha del servidor.
        close(fd_escucha);
        // Abortar el programa.
        abort();
    }

    // ---------------------------------- BIND ----------------------------------
    /*
    // Permitir que varios sockets se puedan bindear a un puerto al mismo tiempo (Siempre y cuando pertenezcan al mismo usuario)
    err = setsockopt(fd_escucha, SOL_SOCKET, SO_REUSEPORT, &(int){1}, sizeof(int));
    // Verificar si hubo error al permitir que varios sockets se bindeen a un puerto.
    if(err) {
        // Imprimir por pantalla el mensaje de error.
        error_show("Error al permitir que varios sockets se bindeen a un puerto - Socket servidor");
        // Cerrar el socket de escucha del servidor.
        close(fd_escucha);
        // Abortar el programa.
        abort();
    }
    */

    // Asociar el socket a un puerto.
    err = bind(fd_escucha, server_info->ai_addr, server_info->ai_addrlen);
    // Verificar si hubo error al asociar el socket a un puerto.
    if(err == -1) {
        // Imprimir por pantalla el mensaje de error.
        error_show("Error al asociar el socket a un puerto - Socket servidor");
        // Cerrar el socket de escucha del servidor.
        close(fd_escucha);
        // Abortar el programa.
        abort();
    }

    // ---------------------------------- LISTEN ----------------------------------
    // Referenciar al socket que se utilizará para aceptar solicitudes de conexión entrantes.
    err = listen(fd_escucha, SOMAXCONN);
    // Verificar si hubo error al referenciar el socket.
    if(err) {
        // Imprimir por pantalla el mensaje de error.
        error_show("Error al referenciar el socket - Socket servidor");
        // Cerrar el socket de escucha del servidor.
        close(fd_escucha);
        // Abortar el programa.
        abort();
    }

    // Imprimir mensaje de estado en escucha.
    printf("Servidor en estado de escucha - En espera de cliente...\n");

    // Liberar la memoria del serverinfo.
    freeaddrinfo(server_info);

    // ---------------------------------- ACCEPT ----------------------------------
    // Aceptar a un nuevo cliente.
    int fd_conexion = accept(fd_escucha, NULL, NULL);

    // Imprimir mensaje de estado en conexion.
    printf("Servidor en conexion con un cliente\n");

    // ---------------------------------- RECEV ----------------------------------
    // Cantidad de bytes enviados y/o recibidos.
    size_t bytes;

    // Para guardar el entero enviado por el cliente.
    int32_t handshake;
    // Posibles resultados.
    int32_t resultOk = 0;
    int32_t resultError = -1;

    // Recibir valor entero del cliente.
    bytes = recv(fd_conexion, &handshake, sizeof(int32_t), MSG_WAITALL);
    // Verificar si hubo error al recibir entero del cliente.
    if(bytes == -1) {
        // Imprimir por pantalla el mensaje de error.
        error_show("Error al recibir el entero del cliente - Socket servidor");
        // Cerrar el socket de conexion del servidor.
        close(fd_conexion);
        // Cerrar el socket de escucha del servidor.
        close(fd_escucha);
        // Abortar el programa.
        abort();
    }

    // Imprimir mensaje de estado entero recibido.
    printf("Entero recibido con exito\n");

    // ---------------------------------- SEND ----------------------------------
    // Verificar entero enviado por el cliente.
    if (handshake == 1) {
        // Enviar resultado de satisfaccion al cliente.
        bytes = send(fd_conexion, &resultOk, sizeof(int32_t), 0);
        // Verificar si hubo error al enviar resultado de satisfaccion al cliente.
        if(bytes == -1) {
            // Imprimir por pantalla el mensaje de error.
            error_show("Error al enviar resultado de satisfaccion al cliente - Socket servidor");
            // Cerrar el socket de conexion del servidor.
            close(fd_conexion);
            // Cerrar el socket de escucha del servidor.
            close(fd_escucha);
            // Abortar el programa.
            abort();
        }
    } else {
        // Enviar resultado de insatisfaccion al cliente.
        bytes = send(fd_conexion, &resultError, sizeof(int32_t), 0);
        // Verificar si hubo error al enviar resultado de insatisfaccion al cliente.
        if(bytes == -1) {
            // Imprimir por pantalla el mensaje de error.
            error_show("Error al enviar resultado de insatisfaccion al cliente - Socket servidor");
            // Cerrar el socket de conexion del servidor.
            close(fd_conexion);
            // Cerrar el socket de escucha del servidor.
            close(fd_escucha);
            // Abortar el programa.
            abort();
        }
    }

    // Imprimir mensaje de estado enviado.
    printf("Resultado de satisfaccion enviado al cliente\n");

    // Cerrar el socket de conexion del servidor.
    close(fd_conexion);
    // Cerrar el socket de escucha del servidor.
    close(fd_escucha);

    return 0;
}