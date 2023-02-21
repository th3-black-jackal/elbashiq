#include "utils.h"

struct addrinfo *fillServInfo(char *user_addr){
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


