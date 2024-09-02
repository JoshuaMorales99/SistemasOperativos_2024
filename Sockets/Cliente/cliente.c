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

// Definiciones de conexion.
#define IP "127.0.0.1"
#define PUERTO "4444"

// Iniciar modulo cliente.
int iniciarCliente();
// Verificar si ocurrio un error y reportarlo.
void verificarError(int err, int *fd_conexion, const char *mensaje);
// Obtener informacion de la red.
void obtenerInfoRed(const struct addrinfo *hints, struct addrinfo **server_info);
// Crear socket del cliente.
int crearSocket(const struct addrinfo *server_info);
// Conectar con el socket del servidor.
void conectarSocket(const struct addrinfo *server_info, int *fd_conexion);

// -------------------------------------------------------------------------------------------

int main() {
    // Iniciar cliente.
    int fd_conexion = iniciarCliente();

    // Cantidad de bytes enviados y/o recibidos.
    size_t bytes;
    // Entero a enviar.
    int32_t handshake = 1;
    // Para guardar la respuesta del servidor.
    int32_t result;

    // Enviar un entero al servidor.
    bytes = send(fd_conexion, &handshake, sizeof(int32_t), 0);
    // Verificar si hubo error al enviar un entero al servidor.
    verificarError(bytes, &fd_conexion, "Error al enviar un entero al servidor - Socket cliente");

    // Imprimir mensaje de estado enviado.
    printf("Entero enviado correctamente\n");

    // Recibir la respuesta del servidor.
    bytes = recv(fd_conexion, &result, sizeof(int32_t), MSG_WAITALL);
    // Verificar si hubo error al recibir respuesta del servidor.
    verificarError(bytes, &fd_conexion, "Error al recibir la respuesta del servidor - Socket cliente");

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

int iniciarCliente() {
    // Puntero que apunta hacia los datos necesarios para la creación del socket.
    struct addrinfo hints, *server_info = NULL;

    // Inicializar hints
    memset(&hints, 0, sizeof(hints));
    // Usar IPv4.
    hints.ai_family = AF_INET;
    // Usar TCP.
    hints.ai_socktype = SOCK_STREAM;

    // Obtener informacion de la red.
    obtenerInfoRed(&hints, &server_info);
    // Crear el socket del cliente.
    int fd_conexion = crearSocket(server_info);
    // Conectar el cliente con el socket servidor.
    conectarSocket(server_info, &fd_conexion);

    // Liberar la memoria del server_info.
    freeaddrinfo(server_info);

    return fd_conexion;
}

void verificarError(int err, int *fd_conexion, const char *mensaje) {
    // Verificar si ocurrio un error.
    if(err < 0) {
        // Imprimir por pantalla el mensaje de error correspondiente.
        error_show("%s", mensaje);
        // Cerrar socket de conexion del cliente.
        if (fd_conexion != NULL) close(*fd_conexion);
        // Abortar programa.
        abort();
    }
}

void obtenerInfoRed(const struct addrinfo *hints, struct addrinfo **server_info) {
    // Devolver informacion de red sobre la IP y puerto.
    int info = getaddrinfo(IP, PUERTO, hints, server_info);
    // Verificar si hubo error al obtener informacion de red (Si lo hubo, err sera distinto a 0)
    verificarError(info * (-1), NULL, "Error al obtener informacion de red - Socket cliente");
}

int crearSocket(const struct addrinfo *server_info) {
    // Crear el socket del cliente.
    int fd_conexion = socket(server_info->ai_family, server_info->ai_socktype, server_info->ai_protocol);
    // Verificar si hubo error al crear socket de conexion del cliente.
    verificarError(fd_conexion, &fd_conexion, "Error al crear socket de conexion - Socket cliente");

    // Retornar la conexion.
    return fd_conexion;
}

void conectarSocket(const struct addrinfo *server_info, int *fd_conexion) {
    // Conectar el cliente con el socket servidor.
    int err = connect(*fd_conexion, server_info->ai_addr, server_info->ai_addrlen);
    // Verificar si hubo error al conectar el cliente con el socket servidor.
    verificarError(err, fd_conexion, "Error al conectar el cliente con el socket servidor - Socket cliente");

    // Imprimir mensaje de estado conectado.
    printf("Se ha conectado correctamente con el servidor\n");
}