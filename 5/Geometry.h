// Geometry.h 

#include <iostream>
using namespace std;

#ifndef GEOMETRY_H
#define GEOMETRY_H

class Geometry{
protected:
	char * Name;
	char * Type;


public:
	Geometry(char* n);
	~Geometry();

	Geometry(Geometry &obj);

	char * GetName();
	char * GetType();


	// virtual abstract functions (to be defined in derived classes)
	virtual double ComputeVolume() = 0;
	virtual double ComputeSurface() = 0;


};

#endif 