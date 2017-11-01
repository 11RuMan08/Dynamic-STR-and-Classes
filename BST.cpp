#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>	
#include <ctype.h>
#include <iostream> 

using namespace std;

// Создадим класс, в котором зададим необходимые функции и переменные.

struct Branch // Создаем структуру для ветки бинарного дерева.
{
	int Data; // Поле для полезной информации (целое чисто).
	Branch *LeftBranch = nullptr; // Указатель на левую ветку.
	Branch *RightBranch = nullptr; // Указатель на правую ветку.
};

class BST {
private:
	bool find = false;
	Branch *root = nullptr; // Указатель на корень дерева.
	void search_el(bool &find, Branch *root, int searching);
	void add(int data, Branch **root); // Добавить элемент.
	void TRAVERSE(Branch *root); // Пройтись по дереву.
	void delete_tree(Branch *root);
public:
	void delete_tree();
	bool search_el(int searching);
	void add(int data);
	void AddRoot(int data); // Добавить Корень.
	bool isNOTempty();
	void TRAVERSE();
};

// А теперь MAIN.

int main() {

	BST tree;

	int request = -1;

	cout << "Work with BST" << endl << endl;
	cout << "a request to action" << endl;
	cout << "1 - add element" << endl;
	cout << "2 - search" << endl;
	cout << "3 - search element" << endl;
	cout << "4 – delete tree" << endl;
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
			tree.add(data);
			break; }

		case 2:
		{if (tree.isNOTempty()) {
			tree.TRAVERSE();
		}
		else
			cout << "No elements in tree" << endl;
		break;
		}
		case 3:
		{
			int elem;
			cout << endl << "request for searching element - ";
			cin >> elem;
			if (tree.search_el(elem))
				cout << elem << " in tree" << endl;
			else
				cout << elem << " NOT in tree" << endl;
			break;
		}
		case 4:
		{
			tree.delete_tree();
			break;
		}
		default: break;
		}
	}
	return 0;
}

// Объявляем функции.

void BST::delete_tree(Branch *root) {
	if (!root) {
		return;
	}
	delete_tree(root->LeftBranch);
	delete root;
	delete_tree(root->RightBranch);
}

void BST::delete_tree() {
	delete_tree(root);
}


void BST::search_el(bool &find, Branch *root, int searching) {
	if (!root) {
		return;
	}
	search_el(find, root->LeftBranch, searching);
	if (root->Data == searching)
		find = true;
	search_el(find, root->RightBranch, searching);
}

bool BST::search_el(int searching) {
	find = false;
	search_el(find, root, searching);
	if (find)
		return true;
	else
		return false;
}

bool BST::isNOTempty() {
	if (root == nullptr) {
		return false;
	}
	else {
		return true;
	}
}

void BST::add(int data) {
	if (!isNOTempty()) {
		AddRoot(data);
	}
	else {
		add(data, &root);
	}
}

void BST::add(int NewData, Branch **cur_node) {
	if (*cur_node != nullptr) {
		if ((*cur_node)->Data < NewData) {

			add(NewData, &((*cur_node)->RightBranch));
		}
		else {

			add(NewData, &((*cur_node)->LeftBranch));
		}
	}
	else
	{
		*cur_node = new Branch;
		(*cur_node)->Data = NewData;

	}
}

void BST::AddRoot(int NewData) {
	Branch* Root = new Branch;
	Root->Data = NewData;
	root = Root;
}

void BST::TRAVERSE(Branch *root) {
	if (!root) {
		return;
	}
	TRAVERSE(root->LeftBranch);
	cout << root->Data << " ";
	TRAVERSE(root->RightBranch);
}

void BST::TRAVERSE() {
	TRAVERSE(root);
}
