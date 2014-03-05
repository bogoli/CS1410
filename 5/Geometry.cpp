// Geometry.cpp
#include "Geometry.h"

Geometry::Geometry(char* n){
	// inside Geometry Constructor
	Name = new char[30];
	Name = n;
	Type = new char[30];
}


Geometry::Geometry(Geometry &obj){
	// copy constructor 

	Name = new char[30];
	Type = new char[30];

	for(int i = 0; i < 30; ++i){
		Name[i] = obj.Name[i];
		Type[i] = obj.Type[i];

	}
}


Geometry::~Geometry(){
	// inside Geometry Deconstructor
}

char * Geometry::GetName(){
	return this->Name;
}

char * Geometry::GetType(){
	return this->Type; 
}


/*  VIRTUAL FUNCTIONS don't need to be here, because they were set to 0 in the .h file.

	double Geometry::ComputeVolume()=0;
		// inside virtual function (will be defined in derived classes)

	double ComputeSurface()=0;
		// inside virtual function (will be defined in derived classes)

*/ 

