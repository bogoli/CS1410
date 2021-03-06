// Prism.cpp
#include "Geometry.h"
#include "Triangle.h"
#include "Prism.h"
#include <cmath>

void Prism::setType(){
	this->Type = "Prism";
}


Prism::Prism(char* n, int b, int h, int l):Triangle(n,b,h){
	length = l;
	this->setType();
}

Prism::~Prism(){

}

// these are virtual in the parent class
double Prism::ComputeVolume(){
	return base*height*length/2;
}

double Prism::ComputeSurface(){
	// calculate hypoteneus
	double hyp = sqrt((base*base) + (height*height));
	return ((base*length) + (height*length) + (hyp*length) + (base*height));
}


