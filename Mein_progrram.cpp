#include "stdafx.h"
#include <stdlib.h> 
#include <iostream> 
#include "Stack.h"

using namespace std;

int main(int argc, char** argv){
	Stack stack;
	int request=-1;
	cout << "a request to action" << endl;
	cout << "1 - push" << endl;
	cout << "2 - pop" << endl;
	cout << "3 - get_size" << endl;
	cout << "0 - exit" << endl;
	while (request != 0)
	{
		cout << endl << "your choice : ";
		cin >> request;
		switch (request) {
		case 1:
		{
			int data;
			cout << "Added data = ";
			cin >> data;
			stack.push(data);
		}break;

		case 2:
		{
			if (stack.isEmpty()) {
				cout << "requested data = " << stack.pop() << endl;
			} else {
				cout << "No elements in stack" << endl;
			}
		}break;
		case 3:
		{
			cout << "Size of stack = " << stack.get_size()<<endl;
		}
		default: break;
		}
	}
	//_gettch();
	return 0;
}
