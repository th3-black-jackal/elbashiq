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
	struct addrinfo hints;
	struct addrinfo *servinfo;
	int status;
	int socket_desc, new_fd;
	int desc, new_desc;
	char ipstr[INET6_ADDRSTRLEN];
	char s[INET6_ADDRSTRLEN];
	char msg[MAXDATASIZE];
}SearchContext;

void initSearchContext(SearchContext *ctx);
int searchList(SearchContext *ctx, const char *user_data);
void printResolvedAddress(const SearchContext *ctx);
int connectToResolvedAddress(SearchContext *ctx);
void bindSocket();
void startServer();
void sendMsg(char *, int);
void sendFile(unsigned int, const char *, int);      
void recvMsg(int);
void recvFile(int);
void connectToServer();

#endif

