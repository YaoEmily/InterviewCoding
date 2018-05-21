#include <iostream>
#include "StackWithMin.h"
using namespace std;

int main(void){
	StackWithTop stack;
	
	stack.push(3);
	cout << "The min element is " << stack.min() << endl;

	stack.push(4);
	cout << "The min element is " << stack.min() << endl;

	stack.push(2);
	cout << "The min element is " << stack.min() << endl;

	stack.pop();
	cout << "The min element is " << stack.min() << endl;

	stack.push(0);
	cout << "The min element is " << stack.min() << endl;

	stack.push(1);
	cout << "The min element is " << stack.min() << endl;

	stack.push(6);
	cout << "The min element is " << stack.min() << endl;

	system("pause");
}