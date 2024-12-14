#include "el_bashiq.h"





int main(int argc, char **argv){
	if(argc < 2){
		fprintf(stderr, "Usage: %s <server_ip>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	const char *user_addr = argv[1];
	SearchContext ctx;
	initSearchContext(&ctx);
	if(searchList(&ctx, user_addr) == 0){
		printResolvedAddress(&ctx);
		if(connectToResolvedAddress(&ctx) == 0){
			printf("Connection successful.\n");
		} else {
			printf("Failed to connect.\n");
		}
		
	} else {
		printf("Failed to resolve address.\n");
	}
	if(bindSocket(&ctx) != 0){
		fprintf(stderr, "Failed to bind socket\n");
		freeaddrinfo(ctx.servinfo);
		return 1;
	}
	printf("Server setup successfully.\n");
	if(startServer(&ctx) != 0){
		fprintf(stderr, "Failed to accept connections\n");
		freeaddrinfo(ctx.servinfo);
		close(ctx.socket_desc);
		return 1;
	}
	printf("Server is running and connection accepted.\n");
	freeaddrinfo(ctx.servinfo);
	close(ctx.socket_desc);
	return 0;
}
