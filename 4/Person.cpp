// Person.cpp
/* Lia Bogoev

In addition, you will also need to create a separate class called Person which 
contains five private data members. Each of these data members is a string 
denoting name, address, city, state, and zip-code. Person should have two 
constructors, one with five string parameters that initializes the five strings
in the class and one with no parameters that initializes everything to empty.
*/
#include "Person.h"

Person::Person(){
//	cout << "\tDefault Person constructor\n";
	name = "";
	address = "";
	city = "";
	state = "";
	zip = "";
}


Person::Person(string n, string a, string c, string s, string z){
//	cout << "\tCustom Person constructor\n";
	name = n;
	address = a;
	city = c;
	state = s;
	zip = z;
}

Person::~Person(){
//	cout << "\tPerson Destructor" << endl;
}

void Person::printPerson(){
	cout << "\tName:    " << name << endl;
	cout << "\tAddress: " << address << endl;
	cout << "\tCity:    " << city << endl;
	cout << "\tState:   " << state << endl;
	cout << "\tZip:     " << zip << endl << endl;
}
// getters
string Person::getName(){
	return name;
}

string Person::getAddress(){
	return address;
}

string Person::getCity(){
	return city;
}

string Person::getState(){
	return state;
}

string Person::getZip(){
	return zip;
}

// setters
void Person::setName(string n){
	name = n;
}

void Person::setAddress(string a){
	address = a;
}

void Person::setCity(string c){
	city = c;
}

void Person::setState(string s){
	state = s;
}

void Person::setZip(string z){
	zip = z;
}







