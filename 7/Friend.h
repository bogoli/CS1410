// Friend.h

#include <iostream>
#include <cstring>
#include <string>
using namespace std;

#ifndef FRIEND_H
#define FRIEND_H

class Friend{
private:
	char * screenName;
	char * interests;
	int age;

public:
	Friend(char*, char*, int);
	Friend();
	~Friend();

	char* getName();
	char* getInterests();
	int getAge();

	void setName(char *);
	void setInterest(char *);
	void setAge(int);
};


#endif