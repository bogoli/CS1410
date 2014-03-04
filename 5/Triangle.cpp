// Triangle.cpp

#include "Geometry.h"
#include "Triangle.h"
#include "math.h"

Triangle::Triangle(char* n, int l, int w):Geometry(n){
	length = l;
	width = w;
	Type = "Triangle";
}

Triangle::~Triangle(){
	// delete Name;
	// delete Type;
}

// these are virtual in the parent class
double Triangle::ComputeVolume(){
	// this will compute the area of the Triangle
	return base*height/2;
}

double Triangle::ComputeSurface(){
	// this will compute the perimeter of the Triangle
	// considering this is a right triangle

	double hyp = sqrt((base*base) + (height*height));
	return (hyp + base + height);

}
