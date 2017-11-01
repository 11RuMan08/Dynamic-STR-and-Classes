// стук.cpp: определяет точку входа для консольного приложения.
#include <stdlib.h> 
#include "stdafx.h" 
#include <iostream> 
#include <windows.h> 
#include "stdafx.h"

using namespace std;

struct node_s {
	int data;
	node_s* prev;
};

class stack_cl {
private:
node_s *stack_adress = nullptr; //top глобальная переменная,убрать
int pop_top(node_s*);
public:
	void push(int);
	int pop();
};





int _tmain(int argc, _TCHAR* argv[]) {
	stack_cl ST;
	ST.push(120);
	ST.push(220);
	cout << ST.pop() << endl;
	cout << ST.pop() << endl;
	_gettch();
	return 0;
}

int stack_cl::pop() {
	int a= pop_top(stack_adress);
	return a;
}

int  stack_cl::pop_top(node_s* top) {
	int saved_data = top->data;
	stack_adress = top->prev;
	delete top;
	//saved_data;
	return saved_data;
}

void  stack_cl::push(int new_data) {
	node_s* node = new node_s;
	node->data = new_data;
	node->prev = stack_adress;
	stack_adress = node;
}
