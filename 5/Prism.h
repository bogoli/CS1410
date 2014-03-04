// Prism.h

#ifndef PRISM_H
#define PRISM_H

class Prism : public Triangle{
private: 
	void setType();
protected: 
	int length; 

public:
	Prism(char* n, int b, int h, int l);
	~Prism();

	// these are virtual in the grandparent class
	double ComputeVolume();
	double ComputeSurface();
};

#endif