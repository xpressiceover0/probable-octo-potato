#include <stdio.h>
#include <sys/sockets.h>
//Contiene la estructura SOCKADDR y las funciones:
/*int     accept(int socket, struct sockaddr *address, socklen_t *address_len);
int     bind(int socket, const struct sockaddr *address, socklen_t address_len);
int     connect(int socket, const struct sockaddr *address, socklen_t address_len);
int     getpeername(int socket, struct sockaddr *address, socklen_t *address_len);
int     getsockname(int socket, struct sockaddr *address, socklen_t *address_len);
int     getsockopt(int socket, int level, int option_name, void *option_value, socklen_t *option_len);
int     listen(int socket, int backlog);
ssize_t recv(int socket, void *buffer, size_t length, int flags);
ssize_t recvfrom(int socket, void *buffer, size_t length, int flags, struct sockaddr *address, socklen_t *address_len);
ssize_t recvmsg(int socket, struct msghdr *message, int flags);
ssize_t send(int socket, const void *message, size_t length, int flags);
ssize_t sendmsg(int socket, const struct msghdr *message, int flags);
ssize_t sendto(int socket, const void *message, size_t length, int flags, const struct sockaddr *dest_addr, socklen_t dest_len);
int     setsockopt(int socket, int level, int option_name, const void *option_value, socklen_t option_len);
int     shutdown(int socket, int how);
int     socket(int domain, int type, int protocol);
int     socketpair(int domain, int type, int protocol, int socket_vector[2]);
*/
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>

int main(int args, const char *kwargs[])
{
	if (args > 1)
	{
		int server_socket, cliente_socket, longitud_cliente, puerto;
		
		puerto = atoi(kwargs[1]); //convierte string en int
		
		struct sockdir server;
		struct sockdir cliente;
		//sockdir ya esta definido en la libreria 
		
		server.sin_family = AF_INET;
		//AF_INET: si se desea usar una direccion de internet
		//AF_UNIX: si se desea usar un sistema de archivos
		
		server.sin_port = htons(puerto); 
		bzero( &server.sin_zero, 8);
		
		if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)))
		{
			perror("Error al abrir el socket\n");
			return -1;
		}
		
		if (bind(server_socket,(struct sockdir *) &server, sizeof(struct sockdir)) ==-1 )
		{
			perror("No se puede abrir el puerto %s\n", kwargs[1]);
			return -2;
		}
		
		if (listen(server_socket, 5))
		{
			perror("Falla en el modo escucha");
			return -3;
		}
		
		longitud_cliente=sizeof( struct sockdir_in);
		
		if ((cliente_socket=accept( server, socket, struct sockdir *) &cliente, &longitud_cliente))== -1)
		{
			printf("No se pudo aceptar la conexion");
			return -4;
		}
		
		char str[INET_ADDRSTRLEN];
		inet_ntop(AF_INET, &(client.sin_addr), str, INET_ADDRSTRLEN);
		printf("Se conecto un cliente desde %s : %d ", str, client.sin_port);
		send(client_socket, "Bienvenido a mi serv\n", 26, 0);
		printf("Saludo enviando\n");
		
		shutdown(cliente_socket, 2);
		shutdown(server_socket, 2);
	}
	else
	{
		printf("No se ha indicado el puerto, por favor indique el puerto");
		return -5;
	}
	
	return 0;
}
