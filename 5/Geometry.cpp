// Geometry.cpp
#include "Geometry.h"

Geometry::Geometry(char* n){
	// inside Geometry Constructor
	Name = new char[30];
	Name = n;
	Type = new char[30];
}


void Geometry::PrintGeometry(){
	cout << "Name: " << this->Name << endl;
	cout << "Type: " << this->Type << endl; 

}

/*
Geometry::Geometry(Geomtery &obj){
	// copy constructor 

}
*/


Geometry::~Geometry(){
	// inside Geometry Deconstructor

}

char * Geometry::GetName(){
	return this->Name;
}

char * Geometry::GetType(){
	return this->Type; 
}


/*  VIRTUAL FUNCTIONS

double Geometry::ComputeVolume()=0;
	// inside virtual function (will be defined in derived classes)

double ComputeSurface()=0;
	// inside virtual function (will be defined in derived classes)

*/ 