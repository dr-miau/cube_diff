#include <fstream>
#include <iostream>
#include "cubeDiff.h"

float *readCube()
{
	std::string cubeFile{};
	std::getline(std::cin,cubeFile);
	std::ifstream ifile(cubeFile);
	
	//File title
	std::string title{};
	std::getline(ifile,title);
	
	//Cell parameters (CRYSTAL format)
	double cellP[6];
	ifile >> cellP[0] >> cellP[1] >> cellP[2] 
		>> cellP[3] >> cellP[4] >> cellP[5];
	
	//Number of atoms
	int nAtoms{};
	ifile >> nAtoms;
	
	//Position of origin
	double origin[3];
	ifile >> origin[0] >> origin[1] >> origin[2]; 

	//Grid information
	int gridN[3];
	double gridStep[9];
	for(int i=0;i<3;i++)
	{
		ifile >> gridN[i];
		for(int j=0;j<3;j++)
			ifile >> gridStep[(i*3)+j];
	}

	long int totalPoints{gridN[0]*gridN[1]*gridN[2]};
	
	//Atomic positions. PENDING - make an struct.
	int *atomN{ new int[nAtoms]{} };
	double *atomData{ new double[nAtoms*4]{} };

	for(int i=0;i<nAtoms;i++)
	{
		ifile >> atomN[i];
		for(int j=0;j<4;j++)
		       ifile >> atomData[i*4+j];	
	}

	//Volumetric Data
	float *volData{ new float[totalPoints]{} };

	for(int i=0;i<totalPoints;i++)
		ifile >> volData[i];

	for(int i=0;i<nAtoms;i++)
	{
		std::cout << atomN[i] << ' ';
		std::cout << atomData[(i*4)+1] << '\n';
	}

	delete[] atomN;
	delete[] atomData;

	return volData;
}

