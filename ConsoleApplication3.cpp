#include "stdafx.h"
#include <iostream>
using namespace std;
struct Node {
	int data;
	Node *next;
};
struct Queue {
	Node *first;
	Node *last;
};
void Creation_fe(Queue *queue) {
	queue->first = new Node;
	queue->first->next = NULL;
	queue->last = queue->first;
}
int Q_Pop(Queue *queue) {
	int value;
	value = queue->first->next->data;
	queue->first = queue->first->next;
	return value;
}
void Q_Push(Queue *queue) {
	int value;
	cout << "Value "; cin >> value;
	queue->last->next = new Node;
	queue->last = queue->last->next;
	queue->last->data = value;
	queue->last->next = NULL;
	cout << "Element has added";
}

void main() {
	Queue Queue;
	Creation_fe(&Queue);
	int choice;
	do {
		cout << "1 - First In" << endl;
		cout << "2 - Last Out" << endl;
		cout << "0 - EXIT" << endl << endl;
		cout << "Your choice- "; cin >> choice;
		switch (choice) {
		case 1:
			Q_Push(&Queue);
			break;
		case 2:
			if
				(Queue.first == Queue.last) cout << "Queue is empty" << endl;
			else
				cout << "first element - " << Q_Pop(&Queue) << endl;
			break;
		case 0:
			break;
		default:
			cout << endl << "error - command not determinate";
			break;
		}
	} while (choice != 0);
	_gettch();
}