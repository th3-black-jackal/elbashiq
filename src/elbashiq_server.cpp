#include "elbashiq_server.hpp"

ClientHandler::ClientHandler(int client_fd, struct sockaddr_storage client_addr): client_fd(client_fd), client_addr(client_addr){}

ClientHandler::~ClientHandler(){
	if(client_fd != -1){
		close(client_fd);
	}
}

void ClientHandler::handle(){
	std::string client_ip = getClientIP();
	std::cout<<"Connected to client: "<< client_ip <<"\n";
	char buffer[1024];
	ssize_t bytes_read;
	while((bytes_read = recv(client_fd, buffer, sizeof(buffer), 0)) > 0){
		buffer[bytes_read] = '\0';
		std::string message(buffer);
		if(message == "quit\n" || message == "quit\r\n"){
			std::cout <<"Client "<<client_ip << "sent 'quit'. Closing connection"<<"\n";
			break;
		}
		std::cout <<"Received from "<<client_ip<<": "<<std::string(buffer, bytes_read)<<"\n";
		if(send(client_fd, buffer, bytes_read, 0) ==  -1){
			perror("couldn't echo back to client");
			break;
		}
	}
	if(bytes_read == 0){
		std::cout <<"Client disconnected: "<< client_ip <<"\n";
	} else if (bytes_read < 0){
		perror("Error in receving bytes");
	}
	close(client_fd);
	client_fd = -1;
}

std::string ClientHandler::getClientIP() const{
	char ipstr[INET6_ADDRSTRLEN];
	if(client_addr.ss_family == AF_INET){
		struct sockaddr_in *ipv4 = (struct sockaddr_in *)&client_addr;
		inet_ntop(AF_INET, &(ipv4->sin_addr), ipstr, sizeof(ipstr));
	} else {
		struct sockaddr_in6 *ipv6 = (struct sockaddr_in6 *)&client_addr;
		inet_ntop(AF_INET6, &(ipv6->sin6_addr), ipstr, sizeof(ipstr));
	}
	return std::string(ipstr);
}


Server::Server(const std::string &port) : port(port), server_fd(-1) {}
Server::~Server(){
	if(server_fd != -1){
		close(server_fd);
	}
	for(auto& thread : threads){
		if(thread.joinable()){
			thread.join();
		}
	}
}

void Server::start(){
	bindSocket();
	acceptConnections();
}
void Server::bindSocket(){
	struct addrinfo hints{}, *res;
	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE;
	if(getaddrinfo(nullptr, port.c_str(), &hints, &res) != 0){
		perror("getaddrinfo");
		throw std::runtime_error("Failed to resolve address");
	}


	server_fd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
	if(server_fd == -1){
		perror("Couldn't create socket");
		freeaddrinfo(res);
		throw std::runtime_error("Failed to create socket");
	}
	int yes = 1;
	if(setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(yes)) == -1){
		perror("setsockopt");
		freeaddrinfo(res);
		close(server_fd);
		throw std::runtime_error("Failed to set socket options");
	}

	if(bind(server_fd, res->ai_addr, res->ai_addrlen) == -1){
		perror("Couldn't bind to socket");
		freeaddrinfo(res);
		close(server_fd);
		throw std::runtime_error("Failed to bind socket");
	}

	freeaddrinfo(res);
	if(listen(server_fd, BACKLOG) == -1){
			perror("Couldn't listen to socket");
			close(server_fd);
			throw std::runtime_error("Couldn't listen to socket");
	}
	std::cout<<"Server is listening on port" << port<<"\n";
}


void Server::acceptConnections(){
	while(true){
		struct sockaddr_storage client_addr;
		socklen_t addr_len = sizeof(client_addr);
		int client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &addr_len);
		if(client_fd == -1){
			perror("Failed to accept connections");
			continue;
		}
		threads.emplace_back([client_fd, client_addr, addr_len](){
				auto handler = std::make_shared<ClientHandler>(client_fd, client_addr);
				handler->handle();
				});
	}
}
