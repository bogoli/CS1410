// Box.h
#ifndef BOX_H
#define BOX_H

#include "Rectangle.h"
#include "Geometry.h"

class Box : public Rectangle{
private: 
	void setType();

protected:
	int height;

public:
	Box(char* n, int l, int w, int h);
	~Box();

	double ComputeVolume();
	double ComputeSurface();
};

#endif