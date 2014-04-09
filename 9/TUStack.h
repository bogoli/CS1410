// TUStack.h

#ifndef TUSTACK_H
#define TUSTACK_H

#include <iostream>
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
	stack[top] = item;
	top += 1;
}

int TUStack::Pop(){
	top -= 1; 
	return stack[top];
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
		// throw outOfBound(i, nSize, "Less than 0.");
	}
	else if (i >= nSize){ 
		// throw outOfBound(i, nSize, "Larger than stack size."); 
	}
	return stack[i];
}

TUStack::~TUStack(){
	delete stack;
}

#endif