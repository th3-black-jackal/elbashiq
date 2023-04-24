#include "el_bashiq_client.h"


void connectToServer(char *server_address){
	/*
	 *
	 * Connect from the client to the server, the server must be running and client has an initialized socket descriptor
	 *
	 */
	struct *addrinfo serverinfo = fillServInfo(server_address);
	int socket_desc = socket(servinfo -> ai_family, servinfo -> ai_socktype,0);
	printf("Socket created\n");
	if(socket_desc == -1){
		perror("Can't creat socket\n");
		
	}
	printf("%d\n", socket_desc);
	if(connect(socket_desc, servinfo->ai_addr, servinfo -> ai_addrlen) == -1){
		close(socket_desc);
		perror("client: connect");
	}	
}


