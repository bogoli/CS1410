// Circle.cpp

#include "Geometry.h"
#include "Circle.h"
#include <cmath>

Circle::Circle(char* n, int r):Geometry(n){
	radius = r; 
	Type = "Circle";
}

Circle::~Circle(){
	// delete Name;
	// delete Type;
}

// these are virtual in the parent class
double Circle::ComputeVolume(){
	// this will compute the area of the Circle
	return 0; 
}

double Circle::ComputeSurface(){
	// This computes the area of the circle
	return PI*radius*radius;
}
