#ifndef el_bashiq_server
#define el_bashiq_server

#include "stdlib.h"
#include "stdio.h"
#include "sys/types.h"
#include "sys/socket.h"
#include "netdb.h"
#include "netinet/in.h"
#include "string.h"
#include "errno.h"
#include "utils.h"


#define BACKLOG 10
#define PORT "1996"
#define MAXDATASIZE 100




char ipstr[INET_ADDRSTRLEN];

char msg[MAXDATASIZE];

struct addrinfo *searchList(char *);

void bindSocket(int socket_desc, struct addrinfo *servinfo); 
void startListening(int socket_desc, int backlog);
void startServer(struct sockaddr *servinfo, int socket_desc);
void sendMsg(char *, int);
void sendFile(unsigned int, const char *, int);
void recvMsg(int);
void recvFile();
void connectToServer();
#endif
