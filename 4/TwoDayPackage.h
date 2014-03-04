// TwoDayPackage.h
// Lia Bogoev

#ifndef TWODAYPACKAGE_H
#define TWODAYPACKAGE_H

#include <iostream>
#include <string>
#include "Person.h"
#include "Package.h"
using namespace std;

class TwoDayPackage:public Package{
	protected:
		double perOunceIncrease;

	public:
		TwoDayPackage(); // default 
		TwoDayPackage(Person s, Person r, int w, double c, double i);
		~TwoDayPackage();

		void setPerOunceIncrease(double i);

		double getPerOunceIncrease();

		double twoDayCost();
};


#endif