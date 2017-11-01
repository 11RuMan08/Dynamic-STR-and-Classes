#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>	
#include <ctype.h>
#include <iostream> 
#include <ctime> 
using namespace std;

char *noun[5] = { "Шопенгауэр", "Маркс", "Ницше", "Лейбниц", "Сократ" };
char *adjective[2][3] = { { "умный", "рассудительный", "экзистенциональный" },{ "непонятый", "мыслящий", "развивающийся" } };
char *verb[3][3] = { { "делал", "умел", "доказывал" },{ "говорил", "обсуждал", "отдыхал" },{ "разсказывал", "повествовал", "развивался" } };
char *quote[4][3] = { { "все" },{ "есть" },{ "атомы", "движение", "гармония" },{ "пустота", "противоречия", "огонь" } };
char *synonyms[5] = { "экзистенцианолист", "материалист", "нигилист", "математик", "мыслитель" };

class quotegen {
private:

public:
	void generate();
};



int main()
{
	setlocale(LC_ALL, "Russian");

	quotegen quoter;

	int request = -1;

	cout << "a request to action" << endl;
	cout << "1 - add element" << endl;
	cout << "0 - exit" << endl;
	while (request != 0)
	{
		cin >> request;
		switch (request) {
		case 1:
		{
			quoter.generate();
			break; };

		default: break;
		}
	}
	_gettch();
	return 0;
}

void quotegen::generate() {
	srand(time(NULL));
	int phylosofist = rand() % 5;
	cout << noun[phylosofist] << endl;
	cout << adjective[0][rand() % 3] << " " << adjective[1][rand() % 3] << endl;
	cout << verb[0][rand() % 3] << " " << verb[1][rand() % 3] << " " << verb[2][rand() % 3] << endl;
	cout << quote[0][0] << " " << quote[1][0] << " " << quote[2][rand() % 3] << " и " << quote[3][rand() % 3] << endl;
	cout << synonyms[phylosofist];
}