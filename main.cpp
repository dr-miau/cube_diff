/***********************************
 * cube_diff -  Build a cube file **
 * ************ as the difference **
 * ************ of two cube files **
 * *********************************
 * Author: Marcos Rivera-Almazo    *
 * GitHub: dr-miau                 *
 * *********************************
 * Usage: ./cube_diff . Enter the  *
 * name of the first cube file,    *
 * then enter the name of the      *
 * second (follow the output       *
 * messages)                       *
 *                                 *
 * The difference is made in order:*
 *     file1.cube - file2.cube     *
 *                                 *
 * See README file for more info.  *
 * *********************************
************************************/

#include <fstream>
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

	std::ofstream diffFile{"difference.cube",std::ios::app};
	diffFile << std::scientific;
	diffFile.precision(5);
	
	for(int i=0;i<totalPoints1;i++)
	{
		if((((i+1)%6)==0) && i!=0)
			diffFile  << '\t' << volData1[i]-volData2[i] << '\n';
		else
			diffFile  << '\t' << volData1[i]-volData2[i];
	}
	diffFile << '\n';

	return 0;
}
