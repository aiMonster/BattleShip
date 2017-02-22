#include <iostream>
#include "Field.h"
using namespace std;



static void print(int amount)		//міні функція яка друкує риски в таблиці
{									//отримує кі-сть штук і виводить їх на екран
	for(int i = 0; i < amount; i++)	// for display function
	{
		cout << char(205);
	}
}


//конструктор для ініціалізації полів
Field_Sample::Field_Sample()
{
	//частина для правильної роботи програми
	for(int a = 0; a < 18; a++)
	{
		for(int b = 0; b < 18; b++)
		{
			my_field[a][b] = SHIP;
			opponent_field[a][b] = SHIP;
		}
	} 
  		
  	//видима частина для користувача
	for(int a = 3; a < 15; a++)
	{
		for(int b = 3; b < 15; b++)
		{
			my_field[a][b] = WATER;
			opponent_field[a][b] = WATER;
		}
	}
}
	
	
//функція для відображення поля на екрані
void Field_Sample::display(int wh) const //1-my_field, 2-opponent_field
{	
	cout << endl << endl;
	cout<< "\t      "<<char(201);
	print(3);
	cout<<  char(203);
	print(31);
	cout << char(187) <<endl;
	cout<< "\t      "<< char(186)<< "   " <<  char(186)<< "  q  w  e  r  t  y  u  i  o  p " << char(186); //друкуємо верхні координати
	
	cout << endl<< "\t      " <<char(204);
	print(3);
	cout << char(206);
	print(31);
	cout << char(185);

	for(int a = 4; a < 14; a++)//
	{
		cout << endl<<  "\t      " << char(186)<< "   " << char(186) <<"\t\t\t\t  "<< char(186) << endl;
		cout <<"\t      " << char(186) << " " << a - 4 << " " << char(186); //виводимо лівий стовпець з нумерацією
		
		for(int b = 4; b < 14; b++)//
		{
			if(wh == 1)
				cout << "  " <<  my_field[a][b];// виводимо кожен символ масиву 
			
			else if(wh == 2)
				cout << "  " <<  opponent_field[a][b];// виводимо кожен символ масиву
		}
		cout << " " << char(186);	
	}
	
	cout << endl<< "\t      " <<char(200);
	print(3);
	cout << char(202);
	print(31);
	cout << char(188);
}
		
			
//конструктор що задає довжину кожному зі своїх кораблів
Field::Field()
	{
		for(int i = 0; i < 4; i++)
		{
			deck_1[i].set_length(1);
		}
		
		for(int i = 0; i < 3; i++)
		{
			deck_2[i].set_length(2);
		}
		
		for (int i = 0; i < 2; i++)
		{
			deck_3[i].set_length(3);
		}
		
		deck_4.set_length(4);
	}
	
	
//запитує у користувача координати та повертає їх у вигляді структури  	
CO Field::ask_co(void)
{
	char a, b;
	CO temp;
	do
	{
		
	
		cout << "\n\n\t\tEnter coordinate(1q, 5y, ...): ";	
		cin >> a >> b;
		switch(a)
		{
			case '0':	temp.a = 4;		break;
			case '1':	temp.a = 5;		break;
			case '2':	temp.a = 6;		break;
			case '3':	temp.a = 7;		break;
			case '4':	temp.a = 8;		break;
			case '5':	temp.a = 9;		break;
			case '6':	temp.a = 10;	break;
			case '7':	temp.a = 11;	break;
			case '8':	temp.a = 12;	break;
			case '9':	temp.a = 13;	break;
			
			default:	temp.a = 0;
		}
		switch(b)
		{
			case 'q':	temp.b = 4;		break;
			case 'w':	temp.b = 5;		break;
			case 'e':	temp.b = 6;		break;
			case 'r':	temp.b = 7;		break;
			case 't':	temp.b = 8;		break;
			case 'y':	temp.b = 9;		break;
			case 'u':	temp.b = 10;	break;
			case 'i':	temp.b = 11;	break;
			case 'o':	temp.b = 12;	break;
			case 'p':	temp.b = 13;	break;
			
			default:	temp.b = 0;
		}
	}
	while((temp.a < 4 || temp.a > 13) || (temp.b < 4 || temp.b > 13));

	//cout << "\nYou entred : " << temp.a << "  " << temp.b;
	return temp;
}


//змінюємо елементи на користувацькому полі бою 
void Field :: change_my_to(int to, CO c)//0-empty, 1-dead_ship
{
	if(to == 0)
	{
		my_field[c.a][c.b] = EMPTY;
	}
	else if(to == 1)
	{
		my_field[c.a][c.b] = DEAD_SHIP;
	}	
}


//змінюємо елеиенти на полі бою з мішенями
void Field :: change_op_to(int to, CO c)
{
	if(to == 0)
	{
		opponent_field[c.a][c.b] = EMPTY;
	}
	else if(to == 1)
	{
		opponent_field[c.a][c.b] = DEAD_SHIP;
	}
}


//повертає певний елемент поля
char Field_Sample :: element (CO cor)
{
	return opponent_field[cor.a][cor.b];
}
	
	
//оточує корабель пустими клітками	
void Field :: surround (Ship ship, Field* opp)	
{
	//вионуємо стільки разів скільки палуб
	for(int i = 0; i < ship.get_length(); i++)
	{
		CO tmp = ship.help(i); //отримуємо координату і-ї балуби даного корабля
		CO tmp_2;
		//оточуємо кожен елемент пустотою якщо він = воді
		for(int a = tmp.a - 1; a <= tmp.a + 1; a++)
		{
			for(int b = tmp.b - 1; b <= tmp.b + 1; b++)
			{
				tmp_2.a = a;
				tmp_2.b = b;
				if(opp->element(tmp_2) == WATER)
				{
					opp->change_op_to(0, tmp_2);
				}
			}
		}
	}
}


//перевіряє чи належить координата якомусь із кораблів
//1 - якщо належить
int Field::belong(CO hit, Field* opp)
{	
	int result;
	//перевіряє 4 одинарних
	for(int i = 0; i < 4; i++)
	{
		result = deck_1[i].belong(hit);
		if(result == 3) return 3;
		else if(result == 1)
		{
			if(deck_1[i].ship_state() == 0) 
			{
				surround(deck_1[i], opp);
				//корабель вбито, а отже його потрібно оточити пустими клітками
				return 1;
			}
			else 
			{
				return 2;
			}
		}
	}
	
	//3 двонарних
	for(int i = 0; i < 3; i++)
	{
		result = deck_2[i].belong(hit);
		if(result == 3) return 3;
		else if(result == 1)
		{
			if(deck_2[i].ship_state() == 0) 
			{
				surround(deck_2[i], opp);
				return 1;
			}
			else 
			{
				return 2;
			}
		}
	}
	
	//2 тринарних
	for (int i = 0; i < 2; i++)
	{
		result = deck_3[i].belong(hit);
		if(result == 3) return 3;
		else if(result == 1)
		{
			if(deck_3[i].ship_state() == 0) 
			{
				surround(deck_3[i], opp);
				return 1;
			}
			else 
			{
				return 2;
			}
		}
	}
	
	//чотриринарний
	result = deck_4.belong(hit);
	if(result == 3) return 3;
		else if(result == 1)
		{
			if(deck_4.ship_state() == 0)
			{
				surround(deck_4, opp);
				return 1;
			} 
			else
			{
				return 2;
			} 
		}
	
	//якщо не належить жодному
	return 0;
}


//перевіряє чи залишились ще цілі кораблі
//якщо 0 - то всі коралі знищено
bool Field::is_alive(void) const
{
	//перевіряє 4 одинарних
	for(int i = 0; i < 4; i++)
	{
		if(deck_1[i].ship_state())
			return 1;
	}
	
	//3 двонарних
	for(int i = 0; i < 3; i++)
	{
		if(deck_2[i].ship_state())
			return 1;
	}
	
	//2 тринарних
	for (int i = 0; i < 2; i++)
	{
		if(deck_3[i].ship_state())
			return 1;
	}
	
	//чотриринарний
	if(deck_4.ship_state())
		return 1;
	
	return 0;
}
		

//виводимо всі елементи масиву, навіть ті що не доступні користувачу		
/*		
void Field_Sample::test_disp(void)
{
	for(int a = 0; a < 18; a++)
	{
		for (int b = 0; b < 18; b++)
		{
			cout << opponent_field[a][b];
		}
		cout << endl;
	}
}
*/	


