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


int getSocketDescriptor(struct addrinfo *servinfo){
	/*
	 * Get a new file descriptor for the required addrinfo
	 */
	int socket_desc;
	if(!servinfo){
		perror("Empty addrinfo\n");
		exit(1);
	}
	printf("Getting socket descriptor\n");
	
	if((socket_desc = socket(servinfo -> ai_family, servinfo->ai_socktype, servinfo -> ai_protocol)) == -1){
	 perror("Couldn't create socket descriptor\n");
	 exit(1);
	}
	return socket_desc;
}

void bindSocket(int socket_desc, struct addrinfo *servinfo){
	/*
	 * 
	 * Binding a socket descriptor to a port to allow the kernel for listening on this port to match a socket descriptor, you can use this with the server module
	 *
	 */
		
	int yes = 1;
	printf("Binding\n");
	if(servinfo == NULL)
		printf("Can't bind to a null address information\n");

	printf("Start socket binding\n");
	int *socket_desc_p = &socket_desc;
	if(setsockopt(*socket_desc_p, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof yes) == -1){
		perror("Address already in use\n");	
		exit(1);
	}
	else {
		socket_desc = *socket_desc_p;
		printf("socket_desc: %d\n", socket_desc);
		if((bind(socket_desc, servinfo -> ai_addr, servinfo -> ai_addrlen)) == -1){
			fprintf(stderr, "Couldn't bind to the required socket descriptor: %d\n", socket_desc);
		}
		else
		{
			//Need a function to prinf the addrinfo content
			printf("Connected to %s\n", servinfo->ai_addr);
		}
	}
}

void startListening(int socket_desc, int backlog){
	int *socket_desc_p;
	socket_desc_p = &socket_desc;
	if((listen(*socket_desc_p, backlog)) == -1){
		fprintf(stderr, "Can't listening\n");
	}
}

void startServer(struct sockaddr *servinfo, int socket_desc){	
	/*
	 *
	 * Start the server loop by using the initialized socket descriptor, use this function with the server module
	 *
	 */
	int new_fd;
	char s[INET6_ADDRSTRLEN];
	printf("Starting server...\n");	
	while(1){
		socklen_t sin_size = sizeof servinfo;
		if((new_fd = accept(socket_desc, (struct sockaddr *)&servinfo, &sin_size)) == -1){
			perror("accept");
			exit(1);
		}
		else
		{
			printf("Connection success\n");
		}
	}
	//inet_ntop(servinfo->sa_family, get_in_addr((struct sockaddr *) &servinfo, s, sizeof s)); 
	//printf("Server got connection from %s\n", s);
}

