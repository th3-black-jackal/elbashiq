#include "elbashiq_server.hpp"





int main(int argc, char **argv){
	try{
		Server server("8080");
		server.start();
	}catch(const std::exception &ex){
		std::cerr << "Error: "<<ex.what()<<"\n";
		return 1;
	}
	return 0;
}
