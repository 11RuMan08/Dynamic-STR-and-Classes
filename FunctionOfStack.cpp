#include "stdafx.h"
#include "Stack.h"

// clang - C/C++ (Intel perhaps?) compiler

int Stack::pop() {
	int saved_data = top->data;
	top = top->prev;
	size--;
	//saved_data;
	return saved_data;
}

void Stack::push(int new_data) {
	node_s* node = new node_s;
	node->data = new_data;
	node->prev = top;
	top = node;
	size++;
}

int Stack::get_size() {
	return size;
}

bool Stack::isEmpty() {
	if (top == nullptr) {
		return false;
	} else {
		return true;
	}
}

