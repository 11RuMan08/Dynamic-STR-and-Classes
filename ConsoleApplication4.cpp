#include <stdlib.h> 
#include "stdafx.h" 
#include <iostream> 
#include <windows.h> 
#include "stdafx.h"

using namespace std;

int str_size = 0;

struct node_s {
	int data;
	node_s* prev;
};

int pop(node_s*);
void push(int);

node_s* stack_adress = NULL;

int _tmain(int argc, _TCHAR* argv[]) {



	int request = 0;
	cout << "a request to action" << endl;
	cout << "1 - push" << endl;
	cout << "2 - pop" << endl;
	cout << "9 - exit" << endl;
	while (request != 9)
	{
		cout << endl << "your choice : ";
		cin >> request;
		switch (request) {
		case 1:
		{
			int data;
			cout << "Added data = ";
			cin >> data;
			push(data);
		}break;
		case 2:
		{if (str_size <= 0)
			cout << "No elements in stack" << endl;
		else
			cout << "requested data = " << pop(stack_adress) << endl;
		}break;
		case 9:
		{cout << "Goodbye"; }break;
		default: break;
		}
	}


	_gettch();
	return 0;


}

int pop(node_s* top) {
	int saved_data = top->data;
	stack_adress = top->prev;
	delete top;
	//saved_data;
	str_size--;
	return saved_data;
}

void push(int new_data) {
	node_s* node = new node_s;
	node->data = new_data;
	node->prev = stack_adress;
	stack_adress = node;
	str_size++;
}