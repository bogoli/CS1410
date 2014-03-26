// Friend.cpp

#include "Friend.h"

/*
	char[30] screenName;
	char[100] interests;
	int age;
*/

Friend::Friend(char* n, char* i, int a){
	screenName = n;
	interests = i; 
	age = a;
}

Friend::Friend(){

}

Friend::~Friend(){
	
}

char* Friend::getName(){
	return screenName;
}

char* Friend::getInterests(){
	return interests;
}

int Friend::getAge(){
	return age;
}

void Friend::setName(char * n){
	screenName = n;
}

void Friend::setInterest(char * i){
	interests = i;
}

void Friend::setAge(int a){
	age = a;
}

