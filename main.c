#include "el_bashiq.h"





int main(int argc, char **argv){
	SearchContext ctx;
	initSearchContext(&ctx);
	const char *user_addr = "0.0.0.0";
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

	if(ctx.servinfo){
		freeaddrinfo(ctx.servinfo);
	}
	if(ctx.socket_desc != -1){
		close(ctx.socket_desc);
	}
	return 0;
}
