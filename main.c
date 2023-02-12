#include "test_el_bashiq_server.h"


void runTests(){
	testSearchList();
	testGetSocketDescriptorLocalDevice();
	testBindSocketLocalDevice();
}


int main(){
	runTests();
	return 0;
}

