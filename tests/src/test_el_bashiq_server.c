#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include "el_bashiq_server.h"
#include "test_el_bashiq_server.h"

void testSearchList(){
	struct addrinfo *res, *p;
	res = searchList(NULL);
	for(p = res; p != NULL;p = p->ai_next){
		void *addr;
		char *ipver;
		if(p->ai_family == AF_INET){
			struct sockaddr_in *ipv4 = (struct sockaddr_in *)p->ai_addr;
			addr = &(ipv4->sin_addr);
			ipver = "IPv4";
		}
		else
		{
			struct sockaddr_in6 *ipv6 = (struct sockaddr_in6 *)p->ai_addr;
			addr = &(ipv6->sin6_addr);
			ipver = "IPv6";
		}
		inet_ntop(p->ai_family, addr, ipstr, sizeof ipstr);	
		printf(" %s: %s\n", ipver, ipstr);
	}
}

void testGetSocketDescriptorLocalDevice(){
	struct addrinfo *res;
	res = searchList(NULL);
	int socket_desc;
	socket_desc = getSocketDescriptor(res);
	printf("New socket descriptor\n");
	printf("%d\n", socket_desc);

}
