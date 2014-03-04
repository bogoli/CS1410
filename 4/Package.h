// Package.h
// Lia Bogoev

#ifndef PACKAGE_H
#define PACKAGE_H

#include <iostream>
#include <string>
#include "Person.h"
using namespace std;

class Package{
	protected:
		Person sender;
		Person receiver;
		int weight;
		double costPerOunce;

	public:
		Package();
		Package(Person s, Person r, int w, double c);
		~Package(); // default deconstructor

		// getters
		Person getSender();
		Person getReceiver();
		int getWeight();
		double getCost();

		// setters
		void setSender(Person s);
		void setReceiver(Person r);
		void setWeight(int w);
		void setCost(double c);

		// print out information
		void printPackage();
		double packageTotalCost();

		// calculating functions
};

#endif