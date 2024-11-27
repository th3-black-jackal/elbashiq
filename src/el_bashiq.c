#include "el_bashiq.h"




char ipstr[INET6_ADDRSTRLEN];
char s[INET6_ADDRSTRLEN];
char msg[MAXDATASIZE];

//File properties
struct addrinfo hints;
struct addrinfo *servinfo;
int statue;
int *socket_desc, *new_fd;
int desc, new_desc;



void initSearchContext(SearchContext *ctx){
	memset(ctx, 0, sizeof(SearchContext));
	ctx->socket_desc = -1;
	ctx->new_fd = -1;
	memset(&ctx->hints, 0, sizeof(ctx->hints));
	ctx->hints.ai_family = AF_UNSPEC;
	ctx->hints.ai_socktype = SOCK_STREAM;
	ctx->hints.ai_flags = AI_PASSIVE;
}

void searchList(SearchContext *ctx, const char *user_addr){
	if(!ctx || !user_addr){
		fprintf(stderr, "Invalid context or input address.\n");
		return -1;
	}
	ctx->status = getaddrinfo(user_addr, PORT, &ctx->hints, &ctx->servinfo);
	if(ctx->status != 0){
		fprintf(stderr, "Error in getaddrinfo: %s\n", gai_strerror(ctx->status));
		return -1;
	}
	void *addr;
	if(ctx->servinfo->ai_family == AF_INET){
		struct sockaddr_in *ipv4 = (struct sockaddr_in *)ctx->servinfo->ai_addr;
		addr = &(ipv4->sin_addr);
	} else {
		struct sockaddr_in6 *ipv6 = (struct sockaddr_in6 *)ctx->servinfo->ai_addr;
		addr = &(ipv6->sin6_addr);
	}
	inet_ntop(ctx->servinfo->ai_family, addr, ctx->ipstr, sizeof(ctx->ipstr));
	printf("Resolved IP address: %s\n", ctx->ipstr);
	return 0;
}


/*
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
	//printf("%d\n", fd);
	if((numbytes = read(fd, msg, MAXDATASIZE - 1)) == -1){
		perror("recv");
		exit(1);
	}
	msg[numbytes] = '\0';
	//printf("recieved %s\n", msg);
}

 Sending file function:
 It takes 3 paramters which is the file_size, file_name, and the socket_descriptor
/
void sendFile(unsigned int file_size, const char *file_name, int fd){
	 First send file's name
	 Convert file_size to Network Byte Order
	 Second send file's size
	 
	uint32_t network_byte_order = htonl(file_size);
	//Send file name
	int sent_bytes;
	printf("File name length: %lu\n", strlen(file_name));
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
*/
