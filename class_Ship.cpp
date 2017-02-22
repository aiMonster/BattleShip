#include <iostream>
#include <process.h> //дл€ exit(0) у раз≥ помилки вводу
#include "Ship.h" //б≥бл≥отека власних функц≥й
using namespace std;
static void check_length(int c, int l); //внутр≥шн€ функц≥€ €ка перев≥р€Ї чи не викликатиме функц≥€ не≥снуючу палубу


//задаЇмо координати корабл€ по €чейках 
void Ship::set_coordinate(int cell, CO cell_co)//пор€дковий номер €чейки, координата €чейки
{
	check_length(cell, length);//перев≥р€Їмо чи ми не виходимо за меж≥
	ship[cell] = cell_co; //присвоюЇмо координату 
	ship[cell].alive = 1; //робим за умовчуванн€м €чейку ц≥лою (не поранений)
}


//задаЇмо довжини корабл€м		
void Ship::set_length(int l)
{
	length = l;
}


//перев≥р€Ї стан корабл€ (поранений - 2, вбитий - 0, ц≥лий - 1)
int Ship :: ship_state() const
{
	
	int temp_injured = 0;
	for(int i = 0; i < length; i++)
	{
		if(ship[i].alive == 0)
		{
			temp_injured++; //€кщо хоч €кась €чейка ==0, значить поранений
		}
	}
			
	if(temp_injured == 0)
	{
		return 1; //€кщо ц≥лий
	}
	else if (temp_injured == length) //€кщо к≥льк≥сть поранень == довжин≥, значить вбито
	{
		return 0; //€кщо вбито
	}
	else
		return 2;
	
}


//повертаЇ координати //приймаЇ номер палуби
CO Ship :: help (int n)
{
	return ship[n];
}


//повертаЇ довжину даного корабл€
int Ship :: get_length()
{
	return length;
}
	
		
//перев≥р€Ї чи належить дана координата нашому кораблю та каже що з ним трапилось
// 0 - мимо, 1 - поранено або вбито
int Ship :: belong(CO hit) //отримуЇ структру координати €ку перев≥р€Ї
{
	int live = 0;
	for(int i = 0; i < length; i++) //перев≥р€Ї кожну координату даного корабл€
	{
		if (hit.a == ship[i].a && hit.b == ship[i].b)
		{
			if(ship[i].alive == 0) return 3; //This coordinate was
			
			ship[i].alive = 0;
			return 1; //поранено або вбито
		}
	}
	return 0; //€кщо н≥
}
		

//////////////////////////////////////////////////////////////////////////
//функц≥€ €ка перев≥р€Ї чи ми не вийшли за меж≥ довжини корабл€
static void check_length(int c, int l) //номер палуби, довжину корабл€
{
	if(c >= l)
	{
		cout << "\n You made bad thing!\n";
		exit(0);
	}
}


