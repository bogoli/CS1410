// OvernightPackage.h
// Lia Bogoev

#ifndef OVERNIGHTPACKAGE_H
#define OVERNIGHTPACKAGE_H

#include <iostream>
#include <string>
#include "Person.h"
#include "Package.h"

using namespace std;

class OvernightPackage:public Package{
	protected:
		double flatIncrease;

	public:
		OvernightPackage(); // default 
		OvernightPackage(Person s, Person r, int w, double c, double f);
		~OvernightPackage();

		void setFlatIncrease(double f);

		double getFlatIncrease();

		double overnightTotalCost();
};


#endif