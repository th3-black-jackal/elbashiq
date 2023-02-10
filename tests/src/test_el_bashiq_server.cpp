#include <arpa/inet.h>
#include <netinet/in.h>
#include <string>
#include <iostream>
#include "el_bashiq_server.h"
#include "test_el_bashiq_server.hpp"

void testSearchList(){
	struct addrinfo *res, *p;
	res = searchList(NULL);
	for(p = res; p != NULL;p = p->ai_next){
		void *addr;
		std::string ipver;
		if(p->ai_family == AF_INET){
			struct sockaddr_in *ipv4 = (struct sockaddr_in *)p->ai_addr;
			addr = &(ipv4->sin_addr);
			ipver = "IPv4";
		}
		inet_ntop(p->ai_family, addr, ipstr, sizeof ipstr);	
		std::cout<<"Found the following IPs"<<std::endl;
		std::cout<<ipver<<": "<<ipstr<<std::endl;
	}
}
