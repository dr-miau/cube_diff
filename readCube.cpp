#include <fstream>
#include <iostream>
#include "cubeDiff.h"

void readCube()
{
	std::string cubeFile{};
	std::getline(std::cin,cubeFile);

	std::ifstream ifile(cubeFile);

	std::string title{};
	std::getline(ifile,title);
	
	double cellP[6];
	ifile >> cellP[0] >> cellP[1] >> cellP[2] 
		>> cellP[3] >> cellP[4] >> cellP[5];

	int nAtoms{};
	ifile >> nAtoms;

//	std::string gridx;

	for(int i=0;i<6;i++)
		std::cout << cellP[i] << ' ';
	std::cout << nAtoms;
}

