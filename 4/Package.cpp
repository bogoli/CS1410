// Package.cpp
#include "Package.h"
#include "Person.h"

// default constructor
Package::Package(){
	// cout << "\t\tDefault Package Constructor\n";
	sender.setName("Sender");
	receiver.setName("Receiver");
	weight = 0;
	costPerOunce = 0;
}

Package::Package(Person s, Person r, int w, double c){
	cout << "\t\tCustom Package Constructor\n";
	sender = s;
	receiver = r;
	weight = w;
	costPerOunce = c;
}

Package::~Package(){
	cout << "\t\tPackage Destructor\n";
}

// getters
Person Package::getSender(){
	return sender;
}
Person Package::getReceiver(){
	return receiver;
}
int Package::getWeight(){
	return weight;
}
double Package::getCost(){
	return costPerOunce;
}

// setters
void Package::setSender(Person s){
	sender = s;
}
void Package::setReceiver(Person r){
	receiver = r;
}
void Package::setWeight(int w){
	weight = w;
}
void Package::setCost(double c){
	costPerOunce = c;
}


void Package::printPackage(){
	cout << "Sender: \n";
	sender.printPerson();
	cout << "\n\nReceiver: \n";
	receiver.printPerson();
	cout << "\n\nWeight: " << weight << endl;
	cout << "Cost Per Ounce:  " << costPerOunce << endl;

}

double Package::packageTotalCost(){
	return weight * costPerOunce;
}








