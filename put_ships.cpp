#include <iostream>
#include <windows.h> //для періодичного очищення екрану

#include "Field.h"

#include <cstdlib>//для рандомного вибору 
#include <ctime>// ---//--- 
using namespace std;


//розставляємо кораблі у полі
void Field::put_ships(bool who)//0 - yourself, 1 - random
{
	int d,temp; //напрямок, змінна яка вказує чи користувач добре вказав координати, чи потрібно розставити його знову
	CO cord;
	srand(static_cast<unsigned int>(time(0)));//активуємо рандом
	if(who)
	{
		//якщо рандомно, то повідомлямо користувача щоб зачекав
		system("cls");
		//cout << "\n\t\t\t adding ships...";
	}
	
	//ставимо 1 корабель довжиною 4
	do//робити доти, поки корабель не буде виставлений корректно
	{
		temp = 0;
		if(!who)
		{
			system ("cls"); //очищаєм екран від усього лишнього
			display(1);
			cout << "\n\n\tChoose start coordinates of the 4 lenght ship" << endl;
			cord = ask_co();
		
			cout << "\n\tEnter direction(1-Left, 3-Right, 2-Down, 4-Up)\t\t\t";
			d = ask(4);
		}
		else
		{
			cord.a = rand() % 10 + 4;	
			cord.b = rand() % 10 +4;	
			d = rand() % 4 + 1;
		}
		//пробуємо поставити
		temp = putting(d, 4, cord, 0);
	}
	while (temp != 1); //роби лоти, доки вдало та правильно не розмістимо корабель
	
	
	//для корабля довжиною 3, їх має бути 2
	for (int q = 0; q < 2; q++ )
	{
		do//робити доти, поки корабель не буде виставлений корректно
		{
			temp = 0;
			if(!who)
			{
				system ("cls"); //очищаєм екран від усього лишнього
				display(1);
				cout << "\n\n\tChoose start coordinates of the 3 lenght ship" << endl;
				cord = ask_co();
				
				cout << "\n\tEnter direction(1-Left, 3-Right, 2-Down, 4-Up)\t\t\t";
				d = ask(4);	
			}
			else
			{
				cord.a = rand() % 10 + 4;	
				cord.b = rand() % 10 +4;	
				d = rand() % 4 + 1;
			}
			
			temp = putting(d, 3, cord, q);
		}
		while (temp != 1);
	}
	
	
	//для 3 кораблів довжиною 2
	for (int q = 0; q < 3; q++ )
	{
		do//робити доти, поки корабель не буде виставлений корректно
		{
			temp = 0;
			if(!who)
			{
				system ("cls"); //очищаєм екран від усього лишнього
				display(1);
				cout << "\n\n\tChoose start coordinates of the 2 lenght ship" << endl;
				cord = ask_co();
				
				cout << "\n\tEnter direction(1-Left, 3-Right, 2-Down, 4-Up)\t\t\t";
				d = ask(4);	
			}
			else
			{
				cord.a = rand() % 10 + 4;	
				cord.b = rand() % 10 +4;	
				d = rand() % 4 + 1;
			}
			
			temp = putting(d, 2, cord, q);
		}
		while (temp != 1);
	}
	
	
	//для 4 кораблів довжиною 1
	for (int q = 0; q < 4; q++ )
	{
		do//робити доти, поки корабель не буде виставлений корректно
		{
			temp = 0;
			if(!who)
			{
				system ("cls"); //очищаєм екран від усього лишнього
				display(1);
				cout << "\n\n\tChoose start coordinates of the 1 lenght ship" << endl;
				cord = ask_co();
			}
			else
			{
				cord.a = rand() % 10 + 4;	
				cord.b = rand() % 10 +4;	
				d = rand() % 4 + 1;
			}
			
			temp = putting(1, 1, cord, q);
		}
		while (temp != 1);
	}
}


/////////////////////// підфункції ///////////////////////////////////////

//ставимо коребель у відповідне місце
bool Field ::putting(int dir, int len, CO cord, int numb)
{
	bool temp = 0;
	int f = cord.a;
	int s = cord.b;
	
	// якщо напрямок 1
	if(dir == 1)
	{
		if(check_rotation(len, 1, cord) == 1)
		{
			for(int a = 0; a < len; a++)
			{
				my_field[f][s - a] = SHIP;
				CO t;
				t.a = f;
				t.b = s-a;
				switch(len)
				{
					case 1: deck_1[numb].set_coordinate(a, t); break;
					case 2: deck_2[numb].set_coordinate(a, t); break;
					case 3: deck_3[numb].set_coordinate(a, t); break;
					case 4: deck_4.set_coordinate(a, t); break;
				}
			}
			temp = 1;
		}			
	}
	
	
	//якщо напрямок 2
	else if(dir == 2)
	{
		if(check_rotation(len, 2, cord) == 1)
		{
			for(int a = 0; a < len; a++)
			{
				my_field[f + a][s] = SHIP;
				CO t;
				t.a = f+a;
				t.b = s;
				switch(len)
				{
					case 1: deck_1[numb].set_coordinate(a, t); break;
					case 2: deck_2[numb].set_coordinate(a, t); break;
					case 3: deck_3[numb].set_coordinate(a, t); break;
					case 4: deck_4.set_coordinate(a, t); break;
				}
			}
			temp = 1;
		}
	}
	
	
	//якщо напрямок 3
	else if(dir == 3)
	{
		if(check_rotation(len, 3, cord) == 1)
		{
			for(int a = 0; a < len; a++)
			{
				my_field[f][s + a] = SHIP;
				CO t;
				t.a = f;
				t.b = s+a;
				switch(len)
				{
					case 1: deck_1[numb].set_coordinate(a, t); break;
					case 2: deck_2[numb].set_coordinate(a, t); break;
					case 3: deck_3[numb].set_coordinate(a, t); break;
					case 4: deck_4.set_coordinate(a, t); break;
				}
			}
			temp = 1;
		}
	}
	
	//якщо напрямок 4
	else if(dir == 4)
	{
		if(check_rotation(len, 4, cord) == 1)
		{
			for(int a = 0; a < len; a++)
			{
				my_field[f - a][s] = SHIP;
				CO t;
				t.a = f-a;
				t.b = s;
				switch(len)
				{
					case 1: deck_1[numb].set_coordinate(a, t); break;
					case 2: deck_2[numb].set_coordinate(a, t); break;
					case 3: deck_3[numb].set_coordinate(a, t); break;
					case 4: deck_4.set_coordinate(a, t); break;
				}
			}
			temp = 1;
		}
	}
	
	return temp; //1 - корабель успішно поставлено, 0 - потрібно повторити
}


