// OvernightPackage.cpp


#include "Person.h"
#include "Package.h"
#include "OvernightPackage.h"

// EduStudent::EduStudent(string ename, string eid, float escore) : Student(ename, eid, escore) 

OvernightPackage::OvernightPackage() : Package(){
	// default constructor
	Package();
	flatIncrease = 0;
}

OvernightPackage::OvernightPackage(Person s, Person r, int w, double c, double f) : Package(s,r,w,c){
	flatIncrease = f;
}

OvernightPackage::~OvernightPackage(){

}

void OvernightPackage::setFlatIncrease(double i){
	flatIncrease = i;
}

double OvernightPackage::getFlatIncrease(){
	return flatIncrease;
}

double OvernightPackage::overnightTotalCost(){
	return weight * costPerOunce + flatIncrease;
}