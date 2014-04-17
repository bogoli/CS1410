// main.cpp
#include "Set.h"

int main()
{	
	Set list;
	char option;
	int thisnumber;

	while (1)
	{	cout << "Options: (I)nsert (F)ind (D)isplay (R)emove (E)xit  ";
		cin >> option;
		cin.ignore();
		
		switch (option)
		{	
		case 'I':
		case 'i':	
			try{
				cout << "Enter name: ";
				cin >> thisnumber;
				list.Insert(thisnumber);
			} catch(Set::duplicateItem e){
				cout << "duplicate item: " << e.number << endl;
				cout << "exception: " << e.message << endl;
			}
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

		case 'F':
		case 'f':
			cout << "What are you looking for? ";
			cin >> thisnumber;
			list.Find(thisnumber);
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

ostream& operator<<(ostream& out, const Set& obj) { obj.Print(out); return out; }
istream& operator>>(istream& in, Set& obj) { obj.Insert(in); return in; }


*/