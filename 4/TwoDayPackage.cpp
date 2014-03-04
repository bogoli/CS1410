// TwoDayPackage.cpp


#include "Person.h"
#include "Package.h"
#include "TwoDayPackage.h"

// EduStudent::EduStudent(string ename, string eid, float escore) : Student(ename, eid, escore) 

TwoDayPackage::TwoDayPackage() : Package(){
	// default constructor
	Package();
	perOunceIncrease = 0;
}

TwoDayPackage::TwoDayPackage(Person s, Person r, int w, double c, double i) : Package(s,r,w,c){
	perOunceIncrease = i;
}

TwoDayPackage::~TwoDayPackage(){

}

void TwoDayPackage::setPerOunceIncrease(double i){
	perOunceIncrease = i;
}

double TwoDayPackage::getPerOunceIncrease(){
	return perOunceIncrease;
}

double TwoDayPackage::twoDayCost(){
	return (weight * (perOunceIncrease + costPerOunce));
}