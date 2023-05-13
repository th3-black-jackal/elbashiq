#include "el_bashiq_client.h"


void connectToServer(char *server_address){
	/*
	 *
	 * Connect from the client to the server, the server must be running and client has an initialized socket descriptor
	 *
	 */
	struct addrinfo *serverInfo = fillServInfo(server_address);
	int socket_desc = socket(serverInfo -> ai_family, serverInfo -> ai_socktype,0);
	printf("Socket created\n");
	if(socket_desc == -1){
		perror("Can't creat socket\n");
		
	}
	printf("%d\n", socket_desc);
	if(connect(socket_desc, serverInfo->ai_addr, serverInfo -> ai_addrlen) == -1){
		close(socket_desc);
		perror("client: connect");
	}	
}


