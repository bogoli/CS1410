// Lia Bogoev
// A01240372
// CS1410

#include "DIntStack.h"
#include <iostream> 
#include <string>
using namespace std;


string postFixConvert(string str, DIntStack stack){
/*
Push [ onto the stack.
Move from left to right in the infix expression to read each input item until “]” is read
For each input item
If it is a number (i.e., operand), output this number (e.g., capitalized ‘A’ to ‘Z’) 
Else if it is an operator:
	a) If the current input item is ‘(’, push ‘(’ onto the stack.
	b) If the current input item is ‘)’, pop elements off the stack and output them until
	reaching a corresponding ‘(’ symbol. This operation ensures that the elements 
	after ‘(’ is printed in the Last-In-First-Out manner and the ‘(’ 
	symbol is popped off the stack.
	c) If the top operator on the stack has higher precedence than the current input item,
		c.1) pop any operators on the stack which are of higher 
			 precedence and output the popped operators; 
		c.2) push the input operator.
	d) If the top operator on the stack has lower precedence than the current input item,
		push the input operator.
	e) If the current input item is ‘]’, pop any operators on the stack until the stack 
	is empty and output the popped operators.
*/

	string fixedStr = ""; 

	stack.Push((int) str[0]);

	for(int i = 0; i < str.length(); ++i){
		if(str[i] >= 'A' && str[i] <= 'Z'){
			fixedStr.append(1, str[i]);
		}
		else if(str[i] == '('){
			stack.Push(str[i]);
		}
		else if (str[i] == ')'){
			fixedStr.append(1, stack.Pop());
			//while(stack.Top() != '(');
		}
		else if(str[i] == '/'){
			if(stack.Top() == '+' || stack.Top() == '-' || stack.Top() == '*' || stack.Top() == '('){
				// lower precedence 
				stack.Push(str[i]);
			}
		}

		// cout << i << " ";
	}
	cout << endl;
	return fixedStr;
}

int main(){
	int i ;

	DIntStack stack;

	string userInput;
	cin >> userInput;

	try
	{
		cout << postFixConvert(userInput, stack) << endl;
	}
	
	catch (DIntStack::IsEmptyException)
	{
		cout << "The Stack is Empty " << endl ;
	}


	return 0 ;
}
