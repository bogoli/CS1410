// Sphere.h

#ifndef SPHERE_H
#define SPHERE_H

class Sphere : public Circle{
private: 
	void setType();

// no protected, because a sphere just has a radius

public:
	Sphere(char* n, int r);
	~Sphere();

	// these are virtual in the parent class
	double ComputeVolume();
	double ComputeSurface();
};

#endif