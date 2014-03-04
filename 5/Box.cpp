// Box.cpp
#include "Box.h"
#include "Rectangle.h"
#include "Geometry.h"

Box::Box(char* n, int l, int w, int h):Rectangle(n,l,w){
	height = h;
	this->setType();
}
	
Box::~Box(){

}

void Box::setType(){
	this->Type = "Box";
}


double Box::ComputeVolume(){
	return height*length*width;
}

double Box::ComputeSurface(){
	return ((2*height*length) + (2*length*width) + (2*height*width));
}