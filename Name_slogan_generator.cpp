#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>	
#include <ctype.h>
#include <iostream> 

using namespace std;


int main()
{
	setlocale(LC_ALL, "Russian");
	char *array_sl[3][6] = { { "хороший", "отличный", "прекрасный", "неповторимый", "худший","великолепный" },{ "правитель","охранник","представитель","депутат","управлющий","программист" },{"университета", "вселенной","округа","города","страны","мира" } };
	string name;
	int n;
	cout << "enter the lenght of your name - ";
	cin >> n;
	cout << "enter your name - ";
	char*open_text = new char[n];
	cin.ignore();
	cin.getline(open_text, n + 1);
	cout << endl << endl << "slogan with your name" << endl;
	for (int i = 0; i < n; i++)
		cout << open_text[i];
	cout << " - " << array_sl[0][rand() % 5] << " " << array_sl[1][rand() % 5] << " " << array_sl[2][rand() % 5];
	_gettch();
	return 0;
}