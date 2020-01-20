#include <iostream>
#include "cubeDiff.h"

int main()
{ 
	std::cout << "Enter name of first cube file" << '\n';
	float *volData1 {readcube()};

	std::cout << "Enter name of second cube file" << '\n';
	float *volData2 {readcube()};

	return 0;
}
