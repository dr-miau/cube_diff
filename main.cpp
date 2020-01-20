#include <iostream>
#include "cubeDiff.h"

int main()
{ 
	std::cout << "Enter name of first cube file" << '\n';
	long int totalPoints1{};
	float *volData1 {readCube(totalPoints1)};

	std::cout << "Enter name of second cube file" << '\n';
	long int totalPoints2{};
	float *volData2 {readCube(totalPoints2)};

	std::cout << totalPoints1 << totalPoints2 << '\n';

	return 0;
}
