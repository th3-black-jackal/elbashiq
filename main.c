#include "test_el_bashiq_server.h"
#include "test_utils.h"
#include "el_bashiq_client.h"
void runTests(){
	/*testSearchList();
	testGetSocketDescriptorLocalDevice();
	testBindSocketLocalDevice();
	testStartListeningLocalDevice();
	testStartServerLocalDevice();*/
	//testConnectToServer();
	//testFillServInfoLocalDevice(); 
	//testGetSocketDescriptorLocalDevice();
}


int main(){
	//runTests();
	connectToServer("127.0.0.1");
	return 0;
}

