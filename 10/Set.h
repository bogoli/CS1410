// Set.h

#include <string>
#include <iostream>
#include "LList.h"

using namespace std;

#ifndef SET_H
#define SET_H


class Set{
private:
	LList list;
public:
	Set();
	~Set();

	void Insert(int n);

};




#endif