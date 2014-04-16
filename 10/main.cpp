// main.cpp
#include "Set.h"

int main()
{	
	Set list;
	char option;
	int thisnumber;

	while (1)
	{	cout << "Options:  (I)nsert, (D)isplay, (R)emove, (E)xit  ";
		cin >> option;
		cin.ignore();
		
		switch (option)
		{	
		case 'I':
		case 'i':	
			cout << "Enter name: ";
			cin >> thisnumber;
			list.Insert(thisnumber);
			break;
		
		case 'D':  
		case 'd':	
			list.Display();
			break;

		case 'R': 
		case 'r':	
			cout << "Enter name: ";
			cin >> thisnumber;
			list.Delete(thisnumber);
			break;

		case 'E':  
		case 'e':
			exit(0);
			return 0;
		}
	}
}


/*
int operator[](const int) const;
bool operator<(const Set&) const;
Set operator^(const Set&) const;
Set operator+(const Set&) const;
Set operator-(const Set&) const;
*/