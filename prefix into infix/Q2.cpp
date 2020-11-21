#include<iostream>
#include<string>
#include"stack.h"
using namespace std;

char* concatinate(char const* array1, char const* array2) { // concatinate two arrays
	int size;
	for (size = 0; array1[size] != '\0'; size++); // calculate size of 1st array
	for (int i = 0; array2[i]; i++) { // calculate size of 2nd array
		size++;
	}
	char* temp = new char[size + 1]; // use to concatinate both string
	int tempIndex = 0; // contorl temp index
	temp[size] = '\0';
	for (int i = 0; array1[i] != '\0'; i++) { // copy data of 2st array
		temp[tempIndex] = array1[i];
		tempIndex++;
	}
	for (int i = 0; array2[i] != '\0'; i++) { // copy data of 2nd array
		temp[tempIndex] = array2[i];
		tempIndex++;
	}
	return temp;
}


char* tokanization(char * str, int start, int end) { // it will tokanize string in given range
	int size = (end - start) + 1;
	char* temp = new char[size + 1];
	int tempIndex = 0;
	for (int i = start; i < end; i++) {
		temp[tempIndex] = str[i];
		tempIndex++;
	}
	temp[tempIndex] = '\0'; // terminate by null character
	return temp;
}
char* prefixToInfix(char* str) {
	stack<char*> Stack; //use to conver prefix into infix
	int strSize;
	for (strSize = 0; str[strSize] != '\0'; strSize++); // calculate str size
	
	char* inversStr = new char[strSize + 1]; // store str in reverse order
	inversStr[strSize] = '\0'; // terminate array by null char

	int inversStrIndex = 0; // control inverseStr array index
	for (int i = strSize-1; i >=0 ; i--) {
		inversStr[inversStrIndex] = str[i];
		inversStrIndex++;
	}

	//actual execution Start from here of this function

	for (int i = 0; i < inversStrIndex; i++) {
		bool isOperator = false;
		// check is operator present
		if (inversStr[i] == '-' || inversStr[i] == '+' || inversStr[i] == '*' || inversStr[i] == '/') {
			isOperator = true;
		}
		if (isOperator) {
			char *leftOperend = Stack.top(); // store 1st array or expression that store in stack
			Stack.pop();
			char *RightOperend = Stack.top();// store 2nd array or expression that store in stack
			Stack.pop();
			char *temp = concatinate("(", leftOperend);
			temp = concatinate(temp, tokanization(inversStr, i, i + 1));
			temp = concatinate(temp, RightOperend);
			temp = concatinate(temp, ")");
			Stack.push(temp);
		}
		else {
			char* temp = tokanization(inversStr, i, i + 1);
			Stack.push(temp);
		}
	}
	return Stack.top();
}

int main(){
	int opetion = -1;
	cout << "\n\n=======================================";
	cout << "\nPress 0 : exit ";
	cout << "\nElse 1 " << "\n-----> ";
	cin >> opetion;
	cout << "=======================================";

	while (opetion) {
		char prefix[40]; // store input
		
		cout << "\nEnter preifx expression : ";
		cin >> prefix;
		cout << "Prefix or Input: " << prefix << endl;
		cout << "Infix or Output: " << prefixToInfix(prefix);

		cout << "\n\n=======================================";
		cout << "\nPress 0 : exit ";
		cout << "\nElse 1 " << "\n-----> ";
		cin >> opetion;
		cout << "=======================================";

	}
	return 0;
}