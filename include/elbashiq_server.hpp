#ifndef ELBASHIQSERVER_H
#define ELBASHIQSERVER_H

#include <iostream>
#include <string>
#include <memory>
#include <thread>
#include <vector>
#include <arpa/inet.h>
#include <cstring>
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


typedef struct {
	int client_fd;
	struct sockaddr_storage addr;
}ClientConnection;


class ClientHandler{
	public:
	       	ClientHandler(int client_fd, struct sockaddr_storage client_addr);
		~ClientHandler();
		void handle();
	private:
		int client_fd;
		struct sockaddr_storage client_addr;
		std::string getClientIP() const;
};

class Server {
	public:
		Server(const std::string &port);
		~Server();
		void start();
	private:
		std::string port;
		int server_fd;
		std::vector<std::thread> threads;
		void bindSocket();
		void acceptConnections();
};
#endif
/*
void initSearchContext(SearchContext *ctx);
int searchList(SearchContext *ctx, const char *user_data);
void printResolvedAddress(const SearchContext *ctx);
int connectToResolvedAddress(SearchContext *ctx);
int bindSocket();
int startServer();
void sendMsg(char *, int);
void sendFile(unsigned int, const char *, int);      
void recvMsg(int);
void recvFile(int);
void connectToServer();

*/
