// Sphere.cpp
#include "Geometry.h"
#include "Circle.h"
#include "Sphere.h"
#include <cmath>

void Sphere::setType(){
	this->Type = "Sphere";
}

Sphere::Sphere(char* n, int r):Circle(n,r){
	this->setType();
}

Sphere::Sphere(){

}

// these are virtual in the parent class
double Sphere::ComputeVolume(){
	return (4*PI*radius*radius*radius/3);
}

double Sphere::ComputeSurface(){
	return (4*PI*radius*radius);
}


