#include "elbashiq_server.h"

void bindSocket(){
	/*
	 * 
	 * Binding a socket descriptor to a port to allow the kernel for listening on this port to match a socket descriptor, you can use this with the server module
	 *
	 */
	int yes = 1;
	printf("Binding\n");
	if(servinfo == NULL)
		printf("Something wrong\n");
	printf("Creating socket\n");
	if((*socket_desc = socket(servinfo -> ai_family, servinfo -> ai_socktype, servinfo -> ai_protocol)) == 
				-1 ){	
		perror("Can't creat socket\n");
		exit(1);
	}	
	else{
		if(setsockopt(*socket_desc, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof yes) == -1){
		       perror("setsockopt");	
		       exit(1);
		}else {
			printf("socket_desc: %d\n", *socket_desc);
			if((bind(*socket_desc, servinfo -> ai_addr, servinfo -> ai_addrlen)) == -1){
				perror("bind");
			}else{
			printf("%d\n", *socket_desc);
			printf("Connected to %s\n", ipstr);
			printf("%d\n", *socket_desc);
				}
			}
		}	
		if((listen(*socket_desc, BACKLOG)) == -1){
				fprintf(stderr, "Can't listening\n");
		} 
}

void startServer(){	
	/*
	 *
	 * Start the server loop by using the initialized socket descriptor, use this function with the server module
	 *
	 */
	printf("Start server...\n");	
	struct sockaddr_storage their_addr;
	socklen_t sin_size = sizeof their_addr;
	printf("origional socket descriptor: %d\n", *socket_desc);
	if((*new_fd = accept(*socket_desc, (struct sockaddr *)&their_addr, &sin_size)) == -1){
		perror("accept");
		exit(1);
	}oid bindSocket(){
	/*
	 * 
	 * Binding a socket descriptor to a port to allow the kernel for listening on this port to match a socket descriptor, you can use this with the server module
	 *
	 */
	int yes = 1;
	printf("Binding\n");
	if(servinfo == NULL)
		printf("Something wrong\n");
	printf("Creating socket\n");
	if((*socket_desc = socket(servinfo -> ai_family, servinfo -> ai_socktype, servinfo -> ai_protocol)) == 
				-1 ){	
		perror("Can't creat socket\n");
		exit(1);
	}	
	else{
		if(setsockopt(*socket_desc, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof yes) == -1){
		       perror("setsockopt");	
		       exit(1);
		}else {
			printf("socket_desc: %d\n", *socket_desc);
			if((bind(*socket_desc, servinfo -> ai_addr, servinfo -> ai_addrlen)) == -1){
				perror("bind");
			}else{
			printf("%d\n", *socket_desc);
			printf("Connected to %s\n", ipstr);
			printf("%d\n", *socket_desc);
				}
			}
		}	
		if((listen(*socket_desc, BACKLOG)) == -1){
				fprintf(stderr, "Can't listening\n");
		} 
}

void startServer(){	
	/*
	 *
	 * Start the server loop by using the initialized socket descriptor, use this function with the server module
	 *
	 */
	printf("Start server...\n");	
	struct sockaddr_storage their_addr;
	socklen_t sin_size = sizeof their_addr;
	printf("origional socket descriptor: %d\n", *socket_desc);
	if((*new_fd = accept(*socket_desc, (struct sockaddr *)&their_addr, &sin_size)) == -1){
		perror("accept");
		exit(1);
	}
void bindSocket(){
	/*
	 * 
	 * Binding a socket descriptor to a port to allow the kernel for listening on this port to match a socket descriptor, you can use this with the server module
	 *
	 */
	int yes = 1;
	printf("Binding\n");
	if(servinfo == NULL)
		printf("Something wrong\n");
	printf("Creating socket\n");
	if((*socket_desc = socket(servinfo -> ai_family, servinfo -> ai_socktype, servinfo -> ai_protocol)) == 
				-1 ){	
		perror("Can't creat socket\n");
		exit(1);
	}	
	else{
		if(setsockopt(*socket_desc, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof yes) == -1){
		       perror("setsockopt");	
		       exit(1);
		}else {
			printf("socket_desc: %d\n", *socket_desc);
			if((bind(*socket_desc, servinfo -> ai_addr, servinfo -> ai_addrlen)) == -1){
				perror("bind");
			}else{
			printf("%d\n", *socket_desc);
			printf("Connected to %s\n", ipstr);
			printf("%d\n", *socket_desc);
				}
			}
		}	
		if((listen(*socket_desc, BACKLOG)) == -1){
				fprintf(stderr, "Can't listening\n");
		} 
}

void startServer(){	
	/*
	 *
	 * Start the server loop by using the initialized socket descriptor, use this function with the server module
	 *
	 */
	printf("Start server...\n");	
	struct sockaddr_storage their_addr;
	socklen_t sin_size = sizeof their_addr;
	printf("origional socket descriptor: %d\n", *socket_desc);
	if((*new_fd = accept(*socket_desc, (struct sockaddr *)&their_addr, &sin_size)) == -1){
		perror("accept");
		exit(1);
	}

		
}



