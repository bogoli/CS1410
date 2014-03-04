// Triangle.cpp

#include "Geometry.h"
#include "Triangle.h"
#include "math.h"

Triangle::Triangle(char* n, int b, int h):Geometry(n){
	base = b;
	height = h;
	Type = "Triangle";
}

Triangle::~Triangle(){
	// delete Name;
	// delete Type;
}

// these are virtual in the parent class
double Triangle::ComputeVolume(){
	// this will compute the area of the Triangle
	return 0;
}

double Triangle::ComputeSurface(){
	// this will compute the perimeter of the Triangle
	return base*height/2;
}
