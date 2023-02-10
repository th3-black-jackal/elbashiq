#include "el_bashiq_server.h"

/*
char ipstr[INET6_ADDRSTRLEN];
char s[INET6_ADDRSTRLEN];
char msg[MAXDATASIZE];

struct addrinfo hints;
struct addrinfo *servinfo;
int status;
int *socket_desc, *new_fd;
int desc, new_desc;
*/




struct addrinfo *searchList(char *user_addr){
	/*
	 * 
	 * Use this function to call getaddrinfo that intializes the structs for later use 
	 *
	 */
	struct addrinfo hints;
	struct addrinfo *servinfo;
	int status;
	//Just to make sure that the hints struct is empty
	memset(&hints, 0, sizeof hints);
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE;
	if(status = getaddrinfo(user_addr, PORT, &hints, &servinfo) != 0){
		printf("Error in getting IP %d\n%s", status, gai_strerror(status));
	}
	struct addrinfo *result;
	result = (struct addrinfo*)malloc(sizeof(struct addrinfo));
	result = servinfo;
	return result;
	
}


void bindSocket(){
	/*
	 * 
	 * Binding a socket descriptor to a port to allow the kernel for listening on this port to match a socket descriptor, you can use this with the server module
	 *
	 */
	/*
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
		*/
}

void startServer(char *user_addr){	
	/*
	 *
	 * Start the server loop by using the initialized socket descriptor, use this function with the server module
	 *
	 */
	/*
	int *new_fd = searchList(user_addr);
	int *socket_desc = bindSocket();
	printf("Start server...\n");	
	struct sockaddr_storage their_addr;
	socklen_t sin_size = sizeof their_addr;
	printf("origional socket descriptor: %d\n", *socket_desc);
	if((*new_fd = accept(*socket_desc, (struct sockaddr *)&their_addr, &sin_size)) == -1){
		perror("accept");
		exit(1);
	}*/
}

