#ifndef C_SOCKETS_NASSER
#define C_SOCKETS_NASSER

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <string.h>
#include <errno.h>

#define BACKLOG 10
#define PORT "1996"
#define MAXDATASIZE 100


typedef struct {
	extern struct addrinfo hints;
	extern struct addrinfo *servinfo;
	extern int status;
	extern int socket_desc, new_fd;
	extern int desc, new_desc;
	extern char ipstr[INET6_ADDRSTRLEN];
	extern char s[INET6_ADDRSTRLEN];
	extern char msg[MAXDATASIZE];
}SearchContent;

void initSearchContext(SearchContext *ctx);
void searchList(char*);
void bindSocket();
void startServer();
void sendMsg(char *, int);
void sendFile(unsigned int, const char *, int);      
void recvMsg(int);
void recvFile(int);
void connectToServer();

#endif

