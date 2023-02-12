#include "test_el_bashiq_server.h"


void runTests(){
	testSearchList();
	testGetSocketDescriptorLocalDevice();
}


int main(){
	runTests();
	return 0;
}

