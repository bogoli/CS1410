// Geometry.h 

#include <iostream>
using namespace std;

#ifndef GEOMETRY_H
#define GEOMETRY_H

class Geometry
{
protected:
	char * Name;
	char * Type;


public:
	Geometry(char* n, char* t);
	~Geometry();

	char * GetName();
	char * GetType();

	// virtual abstract functions (to be defined in derived classes)
	double ComputeVolume() = 0;
	double ComputeSurface() = 0;
	
};

#endif 