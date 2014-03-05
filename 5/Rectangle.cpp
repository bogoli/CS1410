// Rectangle.cpp

#include "Geometry.h"
#include "Rectangle.h"

Rectangle::Rectangle(char* n, int l, int w):Geometry(n){
	length = l;
	width = w;
	Type = "Rectangle";
}

Rectangle::~Rectangle(){
	// delete Name;
	// delete Type;
}

Rectangle::Rectangle(Rectangle &obj):Geometry(obj){
	length = obj.length;
	width = obj.width;
}

// these are virtual in the parent class
double Rectangle::ComputeVolume(){
	return 0;
}

double Rectangle::ComputeSurface(){
	// this will compute the area of the rectangle
	return length*width;

}
