#include <iostream>
#include <windows.h>
#include "Field.h"
using namespace std;

//виконує постріл
bool Field::shoot(Field* opponent)//отримує об'єкт в який здійснюємо постріл
{
	CO target = ask_co();//запитуємо координату 
	int answer = opponent->belong(target, this); //превіряємо чи влучили, поранили, вбили //якщо вбили оточуємо пустими клітинками
	bool return_value;
	//якщо влучили або поранили
	if(answer == 1 || answer == 2)
	{
		switch(answer)
		{
			case 1: cout << "\n\t\t\t YOU KILLED ME"; break;
			case 2: cout << "\n\t\t\t YOU INJURED ME"; break;
		}
		Sleep(ACTION_RESULT);
		opponent->change_my_to(1, target); //робимо відмітку у оппонента
		change_op_to(1, target); //та в себе на полі
		return 1;//повертаємо 1 щоб дати спробу на другий потріл
	}
	else if(answer == 3 || element(target) == EMPTY)
	{
		//якщо він вже влучав в те місце то всерівно даємо 2 шанс
		cout << "\n\t\t   THIS COORDINATE ALREADY WAS!";
		Sleep(ACTION_RESULT);
		return 1;
	}
	else
	{
		cout << "\n\t\t\t AH-AH-AH LOSER";
		Sleep(ACTION_RESULT);
		opponent->change_my_to(0, target);//робимо відмітку у оппонента
		change_op_to(0, target);//та в себе на полі
		return 0;
	}
}


