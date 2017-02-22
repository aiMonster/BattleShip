#include <iostream>
#include "Field.h"
#include <windows.h> //для паузи

#include <cstdlib>//для рандомного вибору 
#include <ctime>// ---//--- 
using namespace std;


//////////// глобальні змінні, адже нам потрібен доступ з усього файлу програми /////////////
//також вони зберігають значення потрібні для продовження стрільби


int to_continue = 0; //змінна яка вказує що нам робити
//якщо = 0, то виконуємо рандомний постріл
//якщо = 1, то нам потрібно добити корабель

CO target, start_target; //тут тримаємо координати в яку будем стріляти в даний момент, а також зберігаєм координату з якої почали
int dir = 0; //зберігаємо напрямок нашого корабля щоб знати куди продовжувати постріли
CO temp_target; //тимчасові координати для влучної стрільби

int timer = 0; //змінна для підрахунку вистрілів в один корабель для правильної стрільби в чотиринарний корабель

//////////////////////// постріл комп'ютера /////////////////////
bool Field :: rand_shot(Field* opponent) //отимуємо вказівник на об'єкт користувача, щоб перевірити чи потрапили ми
{ 	
	//якщо ми ще не оранили нічого, робимо рандомний постріл
	if(to_continue == 0)
	{
		target = rand_co(); //отримуємо рандомну координату
		//target = ask_co(); //для стрільби вручну (при перевірці системи)
		start_target = target;
		return do_it(opponent, start_target); //робимо постріл
	}
	
	//якщо ми щось поранили, ми продовжуємо стрільбу
	else if(to_continue == 1)
	{
		int temp;
		
		labelik: //сюди ми будем повертатися при зміні підходящих координат
		
		//////// пробуємо стрільяти //////////
		//LEFT
		if((dir == 0 || dir == 2) && is_clear(this, start_target.a, start_target.b - 1))
		//якщо ми ще не знаємо напрямку, ябо якщо він горизонтальний ТА коли в цю координату можна здійснити постріл
		{
			target.a = start_target.a;
			target.b = start_target.b - 1;
			temp = do_it(opponent, target); //робимо постріл
			
			if(temp == 1)
			{
				return 1; //якщо вбили
			}
			else if(temp == 2)
			{
				temp_target = target; //якщо ми поцілили, то можливо від цієї координати будем відштовхуватись
				dir = 2;				//якщо ще не добили
				return 1;
			}
			return 0;	//якщо мимо
			
		}
		
		//UP
		else if((dir == 0 || dir == 1) && is_clear(this, start_target.a - 1, start_target.b))
		{
			target.b = start_target.b;
			target.a = start_target.a - 1;
			temp = do_it(opponent, target);
			
			if(temp == 1)
			{
				return 1;
			}
			else if(temp == 2)
			{
				temp_target = target;
				dir = 1;
				return 1;
			}
			return 0;
		}
		
		//RIGHT
		else if((dir == 0 || dir == 2) && is_clear(this, start_target.a, start_target.b + 1))
		{
			target.a = start_target.a;
			target.b = start_target.b + 1;
			temp = do_it(opponent, target);
			
			if(temp == 1)
			{
				return 1;
			}
			else if(temp == 2)
			{
				temp_target = target;
				dir = 2;
				return 1;
			}
			return 0;
		}
		
		//DOWN
		else if((dir == 0 || dir == 1) && is_clear(this, start_target.a + 1, start_target.b))
		{
			target.b = start_target.b;
			target.a = start_target.a + 1;
			temp = do_it(opponent, target);
			
			if(temp == 1)
			{
				return 1;
			}
			else if(temp == 2)
			{
				temp_target = target;
				dir = 1;
				return 1;
			}
			return 0;
		}
		
		//якщо це не 4 палуба
		if(timer < 3)
		{
			//виконуємо зміну координат та пробуємо виконати постріл
			start_target = temp_target;
			timer++;
			goto labelik;
		}
		
		//якщо це 4-палубний корабель
		//то залежно від напрямку змінюємо координати
		else
		{
			if(dir == 2)
			{
				start_target.b -= 2;
			}
			else if(dir == 1)
			{
				start_target.a -= 2;
			}
			goto labelik;
		}
	}
}


//перевіряємо чи можна виконати постріл в дану координату
bool Field :: is_clear(Field*  field, int a, int b)
{
	int good = 0;
	CO tmp;
	//проходимо через кожну координату навколо потрібної
	for(int i = a - 1; i <= a + 1; i++)
	{
		for (int s = b -1; s <= b + 1; s++)
		{
			tmp.a = i;
			tmp.b = s;
			if(field->element(tmp) == SHIP || field->element(tmp) == DEAD_SHIP)
			{
				good++;
			}
		}
		
	}
	tmp.a = a;
	tmp.b = b;
	
	//і якщо буде більше 1 перешкоди(1 можна, - палуба нашого корабля
	//і ця координата не вода
	if(good > 1 || field->element(tmp) != WATER)
	{
		return 0; //не можна
	}	
	else
	{
		return 1; //можна
	}
}


//зробити постріл
int Field :: do_it(Field* opponent, CO m_target)
{
	//робимо постріл
	int answer = opponent->belong(m_target, this); //превіряємо чи влучили, поранили, вбили //якщо вбили оточуємо пустими клітинками
	// 0 - mimo
	//1 - killed 
	//2 - injured
	//3 - was
	
	if(answer == 0)
	{
		cout << "\n\t\t\t OH-OH-OH I\'M LOSER";
		Sleep(ACTION_RESULT);
		opponent->change_my_to(0, m_target); //робимо відмітку у користувача
		change_op_to(0, m_target); //та в себе на полі
		return 0;
	}
	else if(answer == 1)
	{
		cout << "\n\t\t\t I KILLED YOU";
		Sleep(ACTION_RESULT);
		opponent->change_my_to(1, m_target); //робимо відмітку у користувача
		change_op_to(1, m_target); //та в себе на полі
		
		//а також онуляємо глобальні змінні які потрібні для продовження стрільби
		to_continue = 0;
		dir = 0;
		timer = 0;
		
		return 1;
	}
	else if(answer == 2)
	{
		cout << "\n\t\t\t I INJURED YOU";
		Sleep(ACTION_RESULT);
		opponent->change_my_to(1, m_target); //робимо відмітку у оппонента
		change_op_to(1, m_target); //та в себе на полі
		
		//якщо поранили то потрібно продовжити
		to_continue = 1;
		return 2;
	}
	
	//спрацює лише у випадку якщо ми десь допустили помилку
	else if(answer == 3 || element(m_target) == EMPTY)
	{
		cout << "\n\t\t   I\'M TRYING AGAIN!";
		Sleep(ACTION_RESULT);
		return 1;
	}
}


//отримати рандомну координату
CO Field :: rand_co(void)
{
	srand(static_cast<unsigned int>(time(0)));//активуємо рандом
	CO final_co;
	int amount_free = 0; //кількість вільних клітинок
	for(int a = 4; a < 14; a++)
	{
		for(int b = 4; b < 14; b++)
		{
			if(opponent_field[a][b] == WATER)
			{
				amount_free++;
			}
		}
	}
	
	//вибираємо рандомне число в межах вільних місць
	int our_choise = rand()%amount_free + 1;
	
	amount_free = 0;	
	for(int a = 4; a < 14; a++)
	{
		for(int b = 4; b < 14; b++)
		{
			if(opponent_field[a][b] == WATER)
			{
				amount_free++;
				if(amount_free == our_choise)
				{
					//повертаєм потрібну по рахунку координату
					final_co.a = a;
					final_co.b = b;
					return final_co;
				}
			}
		}
	}
}


