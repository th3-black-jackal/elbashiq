#include "stdlib.h"
#include "stdio.h"
#include "sys/types.h"
#include "sys/socket.h"
#include "netdb.h"
#include "netinet/in.h"
#include "string.h"
#include "errno.h"
#include "c_sockets_nasser.h"

void searchList(char *user_addr){
	socket_desc = &desc;
	memset(&hints, 0, sizeof hints);
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE;
	void *addr;
	char *ipver;	
	if((statue = getaddrinfo(user_addr, PORT, &hints, &servinfo)) != 0){
		printf("Error in getting IP %d\n%s", statue, gai_strerror(statue));
	}
	new_fd = &new_desc;	
}

void bindSocket(){
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
	printf("Start server...\n");	
	struct sockaddr_storage their_addr;
	socklen_t sin_size = sizeof their_addr;
	printf("origional socket descriptor: %d\n", *socket_desc);
	if((*new_fd = accept(*socket_desc, (struct sockaddr *)&their_addr, &sin_size)) == -1){
		perror("accept");
		exit(1);
	}

		
}


void connectToServer(){
	*socket_desc = socket(servinfo -> ai_family, servinfo -> ai_socktype,0);
	printf("Socket created\n");
	if(*socket_desc == -1){
		perror("Can't creat socket\n");
		
	}
	printf("%d\n", *socket_desc);
	if(connect(*socket_desc, servinfo->ai_addr, servinfo -> ai_addrlen) == -1){
		close(*socket_desc);
		perror("client: connect");
	}	
}

void sendMsg(char *msg, int fd){
	if(write(fd, msg, sizeof msg) == -1)
		perror("send");
	shutdown(fd, SHUT_WR);
}

void recvMsg(int fd){
	int numbytes;
	printf("%d\n", fd);
	if((numbytes = read(fd, msg, MAXDATASIZE - 1)) == -1){
		perror("recv");
		exit(1);
	}
	msg[numbytes] = '\0';
	printf("recieved %s\n", msg);
}

/* Sending file function:
 * It takes 3 paramters which is the file_size, file_name, and the socket_descriptor
 */
void sendFile(unsigned int file_size, const char *file_name, int fd){
	/* First send file's name
	 * Convert file_size to Network Byte Order
	 * Second send file's size
	 */
	uint32_t network_byte_order = htonl(file_size);
	//Send file name
	int sent_bytes;
	printf("File name length: %d\n", strlen(file_name));
	if((sent_bytes = write(fd, file_name, strlen(file_name))) == -1){
		perror("send");
		exit(1);
	}
	printf("Sent bytes: %d\n", sent_bytes);
	if((sent_bytes = write(fd, "test", sizeof(uint32_t))) == -1){
		perror("send");	
		exit(1);
	}
	printf("sent bytes: %d\n", sent_bytes);
}
//It takes one paramater which is the socket descriptor 
void recvFile(int fd){
	//First recieve the file name then recvieve the file_size
	char file_name[MAXDATASIZE];
	int file_size;
	char *buffer;
	int numbytes;
	printf("scoket descriptor recvFile: %d\n", fd);
	if((numbytes = read(fd, file_name, MAXDATASIZE - 1)) == -1){
		perror("recv");
		printf("Error number: %s\n", gai_strerror(errno));
		exit(1);
	}
	printf("recieved bytes: %d\n", numbytes);
	file_name[numbytes] = '\0';
	printf("recieved %s\n", file_name);
	//Get file size
	uint32_t network_byte_order = 0;
	numbytes = read(fd, buffer, 4);
	while(numbytes <= 0){
		perror("recv");
		printf("%s\n", gai_strerror(errno));
		exit(1);
		numbytes = read(fd, &network_byte_order, 4);
	}
	buffer[numbytes] = '\0';
	printf("recieved: %d\n", numbytes);
	file_size = ntohl(network_byte_order);
	printf("file size: %s\n", buffer);
}	
