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
	TUStack(){
		nSize = 0;
		stack = NULL;
	}

	TUStack(int n){
		nSize = n;
		stack = new int[nSize];
		top = 0;
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


	~TUStack(){
		delete stack;
	}

	int& operator[ ] (int i){
		if (i < 0 ){
			// throw outOfBound(i, nSize, "Less than 0.");
		}
		else if (i >= nSize){ 
			// throw outOfBound(i, nSize, "Larger than stack size."); 
		}
		return stack[i];
	}
};

#endif