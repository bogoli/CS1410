// TUStack.h

#ifndef TUSTACK_H
#define TUSTACK_H

#include <iostream>
#include <string>
using namespace std;

template <class T>
class TUStack{
private:
	T *stack;	// generic data type
	int nSize;
	int top;

public:
	TUStack();
	TUStack(int n);

	// copy constructor
	TUStack(const TUStack &obj);

	void Push(T item);
	T Pop();

	int Size();
	int Position();
	void print();
	T& operator[ ] (int i);

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
		T duplicateValue;
		string message;


		duplicateItem(int i, int s, T d, string m){
			index = i;
			size = s;
			duplicateValue = d;
			message = m;
		}
	};

};

template <class T>
TUStack<T>::TUStack(){
	nSize = 0;
	stack = NULL;
}  


template <class T>
TUStack<T>::TUStack(int n){
	nSize = n;
	stack = new T[nSize];
	top = 0;
}
// Copy constructor
template <class T>
TUStack<T>::TUStack(const TUStack &obj){
	nSize = obj.nSize ;
	stack = new T[nSize] ;
	for (int i = 0 ; i < nSize ; i++)
	{
		stack[i] = obj.stack[i];
	}
}


template <class T>
void TUStack<T>::Push(T item){
	if(top >= nSize){
		throw fullStack(top, nSize, "Full stack! Cannot push!");
	}
	else{
		for(int i = 0; i < top; ++i){
			if(stack[i] == item){
				throw duplicateItem(i, nSize, item, "Duplicate value detected.");
			}
		}
		stack[top] = item;
		top += 1;
	}
}
template <class T>
T TUStack<T>::Pop(){
	top -= 1; 
	if (top < 0){
		throw emptyStack(top, nSize, "Empty stack! Cannot pop!");
	}
	int topValue = stack[top];
	stack[top] = 0;
	return topValue;

}
template <class T>
int TUStack<T>::Size(){
	return nSize;
}
template <class T>
int TUStack<T>::Position(){
	return top;
}
template <class T>
void TUStack<T>::print(){
	for(int i = 0; i < nSize; ++i){
		cout << i << " " << stack[i] << endl;
	}
}
template <class T>
T& TUStack<T>::operator[ ] (int i){
	if (i < 0 ){
		throw outOfBound(i, nSize, "Less than 0.");
	}
	else if (i >= nSize){ 
		throw outOfBound(i, nSize, "Larger than stack size."); 
	}
	return stack[i];
}
template <class T>
TUStack<T>::~TUStack(){
	// delete stack;
}

#endif