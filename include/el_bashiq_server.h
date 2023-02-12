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

#define BACKLOG 10
#define PORT "1996"
#define MAXDATASIZE 100


//typedef struct addrinfo (*addrinforesult)(addrinfo);

char ipstr[INET6_ADDRSTRLEN];
char s[INET6_ADDRSTRLEN];
char msg[MAXDATASIZE];

//struct addrinfo hints;
//struct addrinfo *servinfo;
//int status;
//int *socket_desc, *new_fd;
//int desc, new_desc;
struct addrinfo *searchList(char *);
int getSocketDescriptor(struct addrinfo *);
void bindSocket(int socket_desc, struct addrinfo *servinfo); 
void startListening(int socket_desc, int backlog);
void startServer();
void sendMsg(char *, int);
void sendFile(unsigned int, const char *, int);
void recvMsg(int);
void recvFile();
void connectToServer();
#endif
