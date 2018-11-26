#include <iostream>
#include <stdlib.h> 
#include <vector>
#include <string>
#include <sstream>
using namespace std;
int main(int argc, char *argv[]) {
	stringstream ss1( argv[1] );
	stringstream ss2( argv[2] );
	vector<string> result1;
	vector<string> result2;

	string substr;
	
	while( ss1.good() )
	{
	    getline( ss1, substr, ',' );
	    result1.push_back( substr );
	}
	while( ss2.good() )
	{
	    getline( ss2, substr, ',' );
	    result2.push_back( substr );
	}
	_sleep(1000);
	cout<<"HAL IP: "<< result1.at(3)<<" HAL PORT: "<< result1.at(4)<<" FREQUENCY: "<<result1.at(2)<<" TRANSMIT PROTOCOL: "<<result1.at(6)<<endl; 

	cout<<"FG IP: "<< result2.at(3)<<" FG PORT: "<< result2.at(4)<<" FREQUENCY: "<<result1.at(2)<<" READ PROTOCOL: "<<result2.at(6)<<endl;

	// std::cout << "Starting program "<< argv[0]<< " on port: "<<argv[1]<<"...\n";
	// _sleep(1000);
	// std::cout << "Receiving data from IP: "<<argv[2]<<"...\n";
	// _sleep(1000);
	// std::cout << "Resolving hosts...\n";
	// _sleep(1000);
	// std::cout << "Success!\n";
	// _sleep(1000);

	return 0;
}
