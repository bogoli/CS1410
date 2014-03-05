#include <iostream>
using namespace std;

int main(){
	extern char **environ;

	int k = 0;

	while (environ[k] != NULL) {
		cout << environ[k] << endl;
		k++; 
	}


return 0;

}