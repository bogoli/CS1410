// TUStack.h

#ifndef TUSTACK_H
#define TUSTACK_H

class TUStack{
private:
	int* stack;
	int nSize;

public:
	TUStack(int n){
		nSize = n;
		stack = new int[nSize];
	}

	~TUStack(){
		delete stack;
	}

	void Push(int item){

	}

	int Pop(){

	}

	int Size(){
		return nSize;
	}

	int Position(){

	}

	// operator[]{}
};

#endif