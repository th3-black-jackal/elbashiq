#ifndef el_bashiq_client
#define el_bashiq_client

#include "stdlib.h"
#include "stdio.h"
#include "sys/types.h"
#include "sys/socket.h"
#include "netdb.h"
#include "netinet/in.h"
#include "string.h"
#include "errno.h"



#define PORT "1996"


struct addrinfo *fillServInfo(char *user_addr);
int getSocketDescriptor(struct addrinfo *servinfo);


#endif
