// TUStack.h

#ifndef TUSTACK_H
#define TUSTACK_H

#include <iostream>
#include <cstring>
#include <string>
using namespace std;

class TUStack{
private:
	int* stack;
	int nSize;
	int top;

public:
	TUStack();
	TUStack(int n);

	void Push(int item);
	int Pop();

	int Size();
	int Position();
	void print();
	int& operator[ ] (int i);

	~TUStack();

	// Exceptions class
	class outOfBound{
	public:
		int index; 
		int size; 
		string message;

		outOfBound(int i, int s, string m){
			index = i;
			size = s;
			message = m;
		}
	};

	class emptyStack{
	public:
		int index;
		int size;
		string message;

		emptyStack(int i, int s, string m){
			index = i;
			size = s;
			message = m;
		}
	};

	class fullStack{
	public:
		int index;
		int size;
		string message;

		fullStack(int i, int s, string m){
			index = i;
			size = s;
			message = m;
		}
	};

	class duplicateItem{
	public:
		int index;
		int size;
		int duplicateValue;
		string message;

		duplicateItem(int i, int s, int d, string m){
			index = i;
			size = s;
			duplicateValue = d;
			message = m;
		}
	};

};

TUStack::TUStack(){
	nSize = 0;
	stack = NULL;
}  

TUStack::TUStack(int n){
	nSize = n;
	stack = new int[nSize];
	top = 0;
}

void TUStack::Push(int item){
	if(top >= nSize){
		throw fullStack(top, nSize, "Full stack! Cannot push!");
	}
	else{
		stack[top] = item;
		top += 1; 
	}
}

int TUStack::Pop(){
	top -= 1; 
	if (top < 0){
		throw emptyStack(top, nSize, "Empty stack! Cannot pop!");
	}
	else{
		int topValue = stack[top];
		stack[top] = 0;
		return topValue;
	}
}

int TUStack::Size(){
	return nSize;
}

int TUStack::Position(){
	return top;
}

void TUStack::print(){
	for(int i = 0; i < nSize; ++i){
		cout << i << " " << stack[i] << endl;
	}
}

int& TUStack::operator[ ] (int i){
	if (i < 0 ){
		throw outOfBound(i, nSize, "Less than 0.");
	}
	else if (i >= nSize){ 
		throw outOfBound(i, nSize, "Larger than stack size."); 
	}
	return stack[i];
}

TUStack::~TUStack(){
	delete stack;
}

#endif