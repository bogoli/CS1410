// Person.h
// Lia Bogoev

#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
using namespace std;


class Person{
	protected:
		string name;
		string address; 
		string city;
		string state;
		string zip;

	public:
		// constructors
		Person();
		Person(string n, string a, string c, string s, string z);
		~Person(); // default deconstructor

		// getters 
		string getName();
		string getAddress();
		string getCity();
		string getState();
		string getZip();

		// setters
		void setName(string n);
		void setAddress(string a);
		void setCity(string c);
		void setState(string s);
		void setZip(string z);

		// print out information
		void printPerson();
};


#endif