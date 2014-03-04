// Rectangle.h

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Geometry.h"

class Rectangle : public Geometry{
protected:
	int length;
	int width;

public:
	Rectangle(char* n, int l, int w);
	~Rectangle();

	// these are virtual in the parent class
	double ComputeVolume();
	double ComputeSurface();
};

#endif