#include "Field.h"


//превіряє чи можна поставити корабель розміром size в напрямку direction з початковою координатою coordinate
bool Field::check_rotation(int size, int direction, CO coordinate)
{
	int temp; // якщо 1 то можна, якщо 0 то ні
	int d = direction;
	int f = coordinate.a; //f - first coordinate
	int s = coordinate.b; //s - second coordinate

	//перевіряємо в залежності від напрямку
	// напрямок 1(Вліво)
	if (d == 1)
	{
		temp = 1;
		for(int a = f - 1; a <= f + 1; a++)
		{
			for(int b = s - size; b <= s + 1; b++)
			{
				if(my_field[a][b] != WATER)
				{
					temp = 0; // якщо якись елемент не дорівнює вільному положенні то корабель вже там бути не може
				}
			}
		}
		return temp; //якщо корабель можна ставити повертаєм 1
	}
	
	//напрямок 2
	else if(d == 2)
	{
		temp = 1;
		for(int a = f - 1; a <= f + size; a++)
		{
			for(int b = s - 1; b <= s + 1; b++)
			{
				if(my_field[a][b] != WATER)
				{
					temp = 0;
				}
			}
		}
		return temp; 
	}
	
	//напрямок 3
	else if (d == 3)
	{
		temp = 1;
		for(int a = f - 1; a <= f + 1; a++)
		{
			for(int b = s - 1; b <= s + size; b++)
			{
				if(my_field[a][b] != WATER)
				{
					temp = 0;
				}
			}
		}
		return temp; 
	}
	
	//напрямок 4
	else if(d == 4)
	{
		temp = 1;
		for(int a = f - size; a <= f + 1; a++)
		{
			for(int b = s - 1; b <= s + 1; b++)
			{
				if(my_field[a][b] != WATER)
				{
					temp = 0;
				}
			}
		}
		
		return temp; 
	}
}


