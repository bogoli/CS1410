// Lia Bogoev
// A01240372
// CS1410

#include "DIntStack.h"
#include <iostream> 
#include <string>
using namespace std;


string postFixConvert(string str, DIntStack stack){
	string fixedStr = ""; 

	stack.Push(str[0]);
	cout << "stack.Top() = " << (char) stack.Top() << endl;

	for(int i = 0; i < str.length(); ++i){
		if((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >='a' && str[i] <= 'z')){
			fixedStr.append(1, str[i]);
		}
		else if(str[i] == '('){
			stack.Push(str[i]);
			cout << "i: " << i <<  " stack.Top() = " << (char) stack.Top() << endl;
		}
		else if (str[i] == ')'){
			while(stack.Top() != '('){
				if(stack.Top() != '('){
					cout << "i: " << i <<  " stack.Top() = " << (char) stack.Top() << endl;
					fixedStr.append(1, stack.Pop());
				}
			}
		}
		else if(str[i] == '/' || str[i] == '*' ){
			stack.Push(str[i]);
			cout << "i: " << i <<  " stack.Top() = " << (char) stack.Top() << endl;
		}
		else if(str[i] == '+' || str[i] == '-'){
			if(stack.Top() == '*' || stack.Top() == '/'){
				// stack has higher precedence --> pop off the stack then push
				fixedStr.append(1,stack.Pop());
				stack.Push(str[i]);
				cout << "i: " << i <<  " stack.Top() = " << (char) stack.Top() << endl;
			}
			else{
				stack.Push(str[i]);
				cout << "i: " << i <<  " stack.Top() = " << (char) stack.Top() << endl;
			}
		}
		else if(str[i] == ']'){
			// end of expression
			while(stack.Top() != '['){
				cout << "i: " << i <<  " stack.Top() = " << (char) stack.Top() << endl;
				if(stack.Top() == '('){
					stack.Pop();
				}
				else{

					fixedStr.append(1,stack.Pop());
				}
			}
		}


		// cout << i << " ";
	}
	return fixedStr;
}

int main(){
	int i ;

	DIntStack stack;
	string userInput;
	// cin >> userInput;

	try{
		/*
		cout << "[A+(B-C)]" << endl;
		cout << postFixConvert("[A+(B-C)]", stack) << endl << endl;

		cout << "[(A+B)+C]" << endl;
		cout << postFixConvert("[(A+B)+C)]", stack) << endl << endl;

		cout << "[(a/b)*(c/d)]" << endl;
		cout << postFixConvert("[(a/b)*(c/d)]", stack) << endl << endl;

		*/
		cout << "[a/(b+c*d-e)]" << endl;
		cout << postFixConvert("[a/(b+c*d-e)", stack) << endl << endl;
		cout << "Should be: abcd*+e-/" << endl;
		/*
		cout << "[a-b*c+d/e]" << endl;
		cout << postFixConvert("[a-b*c+d/e", stack) << endl << endl;
		*/
	} catch (DIntStack::IsEmptyException){
		cout << "The Stack is Empty " << endl ;
	}


	return 0 ;
}
