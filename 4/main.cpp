// main.cpp
// Lia Bogoev 

#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <cstring>

#include "Person.h"
#include "Package.h"
#include "TwoDayPackage.h"
#include "OvernightPackage.h"

int main(int argc, char const *argv[])
{
	ofstream outputFile;
	ifstream inputFile;

	inputFile.open("Package.txt");	
	outputFile.open("ShippingLabel.txt");

while( !inputFile.eof() ){
	
	// figuring out what type of package it is
	char packageType;
	inputFile >> packageType;

	if(packageType == 'P' | packageType == 'p'){
		int weight;
		double cost;
		inputFile >> weight;
		inputFile >> cost; 
		string nameS, addressS, cityS, stateS, zipS, nameR, addressR, cityR, stateR, zipR;
		
		inputFile.ignore();
		getline(inputFile,nameS);
		getline(inputFile, addressS);
		getline(inputFile, cityS);
		getline(inputFile, stateS);
		getline(inputFile, zipS);
		Person sender = Person(nameS, addressS, cityS, stateS, zipS);
		
		getline(inputFile, nameR);
		getline(inputFile, addressR);
		getline(inputFile, cityR);
		getline(inputFile, stateR);
		getline(inputFile, zipR);
		Person receiver = Person(nameR, addressR, cityR, stateR, zipR);
		
		Package package = Package(sender, receiver, weight, cost);
		
		outputFile << "*************** Shipping Label ***************\n\n";
		outputFile << "Delivery Cost: $" << package.packageTotalCost() << endl;
		outputFile << "SENDER: \n";
		outputFile << "\tName:    " << sender.getName() << endl;
		outputFile << "\tAddress: " << sender.getAddress() << endl;
		outputFile << "\tCity:    " << sender.getCity() << endl;
		outputFile << "\tState:   " << sender.getState() << endl;
		outputFile << "\tZip:     " << sender.getZip() << endl << endl;

		outputFile << "RECEIVER: \n";
		outputFile << "\tName:    " << receiver.getName() << endl;
		outputFile << "\tAddress: " << receiver.getAddress() << endl;
		outputFile << "\tCity:    " << receiver.getCity() << endl;
		outputFile << "\tState:   " << receiver.getState() << endl;
		outputFile << "\tZip:     " << receiver.getZip() << endl << endl;
	} // end if 

	if(packageType == 'O' | packageType == 'o'){
		int weight;
		double cost, flatrate;
		inputFile >> weight;
		inputFile >> cost; 
		string nameS, addressS, cityS, stateS, zipS, nameR, addressR, cityR, stateR, zipR;
		
		inputFile.ignore();
		getline(inputFile,nameS);
		getline(inputFile, addressS);
		getline(inputFile, cityS);
		getline(inputFile, stateS);
		getline(inputFile, zipS);
		Person sender = Person(nameS, addressS, cityS, stateS, zipS);
		
		getline(inputFile, nameR);
		getline(inputFile, addressR);
		getline(inputFile, cityR);
		getline(inputFile, stateR);
		getline(inputFile, zipR);
		Person receiver = Person(nameR, addressR, cityR, stateR, zipR);
		
		inputFile >> flatrate;
		inputFile.ignore();
		OvernightPackage package = OvernightPackage(sender, receiver, weight, cost, flatrate);
		
		outputFile << "*************** Shipping Label ***************\n\n";
		outputFile << "Delivery Cost: $" << package.overnightTotalCost() << endl; 
		outputFile << "SENDER: \n";
		outputFile << "\tName:    " << sender.getName() << endl;
		outputFile << "\tAddress: " << sender.getAddress() << endl;
		outputFile << "\tCity:    " << sender.getCity() << endl;
		outputFile << "\tState:   " << sender.getState() << endl;
		outputFile << "\tZip:     " << sender.getZip() << endl << endl;

		outputFile << "RECEIVER: \n";
		outputFile << "\tName:    " << receiver.getName() << endl;
		outputFile << "\tAddress: " << receiver.getAddress() << endl;
		outputFile << "\tCity:    " << receiver.getCity() << endl;
		outputFile << "\tState:   " << receiver.getState() << endl;
		outputFile << "\tZip:     " << receiver.getZip() << endl << endl;


	} // end if 

	if(packageType == 'T' | packageType == 't'){
		int weight;
		double cost, increase;
		inputFile >> weight;
		inputFile >> cost; 
		string nameS, addressS, cityS, stateS, zipS, nameR, addressR, cityR, stateR, zipR;
		
		inputFile.ignore();
		getline(inputFile,nameS);
		getline(inputFile, addressS);
		getline(inputFile, cityS);
		getline(inputFile, stateS);
		getline(inputFile, zipS);
		Person sender = Person(nameS, addressS, cityS, stateS, zipS);
		
		getline(inputFile, nameR);
		getline(inputFile, addressR);
		getline(inputFile, cityR);
		getline(inputFile, stateR);
		getline(inputFile, zipR);
		Person receiver = Person(nameR, addressR, cityR, stateR, zipR);
		
		inputFile >> increase;
		inputFile.ignore();
		TwoDayPackage package = TwoDayPackage(sender, receiver, weight, cost, increase);
		
		outputFile << "*************** Shipping Label ***************\n\n";
		outputFile << "Delivery Cost: $" << package.twoDayCost() << endl; 
		outputFile << "SENDER: \n";
		outputFile << "\tName:    " << sender.getName() << endl;
		outputFile << "\tAddress: " << sender.getAddress() << endl;
		outputFile << "\tCity:    " << sender.getCity() << endl;
		outputFile << "\tState:   " << sender.getState() << endl;
		outputFile << "\tZip:     " << sender.getZip() << endl << endl;

		outputFile << "RECEIVER: \n";
		outputFile << "\tName:    " << receiver.getName() << endl;
		outputFile << "\tAddress: " << receiver.getAddress() << endl;
		outputFile << "\tCity:    " << receiver.getCity() << endl;
		outputFile << "\tState:   " << receiver.getState() << endl;
		outputFile << "\tZip:     " << receiver.getZip() << endl << endl;


	} // end if 
		

}// end while loop 

	
	return 0;
}