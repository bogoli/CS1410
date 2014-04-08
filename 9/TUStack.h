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
	TUStack(int n){
		nSize = n;
		stack = new int[nSize];
		top = 0;
	}

	~TUStack(){
		delete stack;
	}

	void Push(int item){
		stack[top] = item;
		top += 1;
	}

	int Pop(){
		top -= 1; 
		return stack[top];
	}

	int Size(){
		return nSize;
	}

	int Position(){
		return top;
	}

	void print(){
		for(int i = 0; i < nSize; ++i){
			cout << i << " " << stack[i] << endl;
		}
	}
	// operator[]{}
};

#endif