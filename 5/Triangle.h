// Triangle.h

#ifndef TRIANGLE_H
#define TRIANGLE_H

class Triangle : public Geometry{
protected:
	int base;
	int height;

public:
	Triangle(char* n, int b, int h);
	~Triangle();

	// these are virtual in the parent class
	double ComputeVolume();
	double ComputeSurface();
};

#endif