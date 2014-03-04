// Circle.h

#ifndef CIRCLE_H
#define CIRCLE_H

const double PI = 3.1415926;

class Circle : public Geometry{
protected:
	int radius;

public:
	Circle(char* n, int r);
	~Circle();

	// these are virtual in the parent class
	double ComputeVolume();
	double ComputeSurface();
};

#endif