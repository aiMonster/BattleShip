#include <iostream>
#include "Field.h"
#include <windows.h> //��� �����

#include <cstdlib>//��� ���������� ������ 
#include <ctime>// ---//--- 
using namespace std;


//////////// �������� ����, ���� ��� ������� ������ � ������ ����� �������� /////////////
//����� ���� ��������� �������� ������ ��� ����������� �������


int to_continue = 0; //����� ��� ����� �� ��� ������
//���� = 0, �� �������� ��������� ������
//���� = 1, �� ��� ������� ������ ��������

CO target, start_target; //��� ������� ���������� � ��� ����� ������� � ����� ������, � ����� ������� ���������� � ��� ������
int dir = 0; //�������� �������� ������ ������� ��� ����� ���� ������������ �������
CO temp_target; //�������� ���������� ��� ������ �������

int timer = 0; //����� ��� ��������� ������� � ���� �������� ��� ��������� ������� � ������������ ��������

//////////////////////// ������ ����'����� /////////////////////
bool Field :: rand_shot(Field* opponent) //������� �������� �� ��'��� �����������, ��� ��������� �� ��������� ��
{ 	
	//���� �� �� �� ������� �����, ������ ��������� ������
	if(to_continue == 0)
	{
		target = rand_co(); //�������� �������� ����������
		//target = ask_co(); //��� ������� ������ (��� �������� �������)
		start_target = target;
		return do_it(opponent, start_target); //������ ������
	}
	
	//���� �� ���� ��������, �� ���������� �������
	else if(to_continue == 1)
	{
		int temp;
		
		labelik: //���� �� ����� ����������� ��� ��� ��������� ���������
		
		//////// ������� �������� //////////
		//LEFT
		if((dir == 0 || dir == 2) && is_clear(this, start_target.a, start_target.b - 1))
		//���� �� �� �� ����� ��������, ��� ���� �� �������������� �� ���� � �� ���������� ����� �������� ������
		{
			target.a = start_target.a;
			target.b = start_target.b - 1;
			temp = do_it(opponent, target); //������ ������
			
			if(temp == 1)
			{
				return 1; //���� �����
			}
			else if(temp == 2)
			{
				temp_target = target; //���� �� ��������, �� ������� �� ���� ���������� ����� ��������������
				dir = 2;				//���� �� �� ������
				return 1;
			}
			return 0;	//���� ����
			
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
		
		//���� �� �� 4 ������
		if(timer < 3)
		{
			//�������� ���� ��������� �� ������� �������� ������
			start_target = temp_target;
			timer++;
			goto labelik;
		}
		
		//���� �� 4-�������� ��������
		//�� ������� �� �������� ������� ����������
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


//���������� �� ����� �������� ������ � ���� ����������
bool Field :: is_clear(Field*  field, int a, int b)
{
	int good = 0;
	CO tmp;
	//��������� ����� ����� ���������� ������� �������
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
	
	//� ���� ���� ����� 1 ���������(1 �����, - ������ ������ �������
	//� �� ���������� �� ����
	if(good > 1 || field->element(tmp) != WATER)
	{
		return 0; //�� �����
	}	
	else
	{
		return 1; //�����
	}
}


//������� ������
int Field :: do_it(Field* opponent, CO m_target)
{
	//������ ������
	int answer = opponent->belong(m_target, this); //��������� �� �������, ��������, ����� //���� ����� ������� ������� ���������
	// 0 - mimo
	//1 - killed 
	//2 - injured
	//3 - was
	
	if(answer == 0)
	{
		cout << "\n\t\t\t OH-OH-OH I\'M LOSER";
		Sleep(ACTION_RESULT);
		opponent->change_my_to(0, m_target); //������ ������ � �����������
		change_op_to(0, m_target); //�� � ���� �� ���
		return 0;
	}
	else if(answer == 1)
	{
		cout << "\n\t\t\t I KILLED YOU";
		Sleep(ACTION_RESULT);
		opponent->change_my_to(1, m_target); //������ ������ � �����������
		change_op_to(1, m_target); //�� � ���� �� ���
		
		//� ����� �������� �������� ���� �� ������ ��� ����������� �������
		to_continue = 0;
		dir = 0;
		timer = 0;
		
		return 1;
	}
	else if(answer == 2)
	{
		cout << "\n\t\t\t I INJURED YOU";
		Sleep(ACTION_RESULT);
		opponent->change_my_to(1, m_target); //������ ������ � ���������
		change_op_to(1, m_target); //�� � ���� �� ���
		
		//���� �������� �� ������� ����������
		to_continue = 1;
		return 2;
	}
	
	//������� ���� � ������� ���� �� ���� ��������� �������
	else if(answer == 3 || element(m_target) == EMPTY)
	{
		cout << "\n\t\t   I\'M TRYING AGAIN!";
		Sleep(ACTION_RESULT);
		return 1;
	}
}


//�������� �������� ����������
CO Field :: rand_co(void)
{
	srand(static_cast<unsigned int>(time(0)));//�������� ������
	CO final_co;
	int amount_free = 0; //������� ������ �������
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
	
	//�������� �������� ����� � ����� ������ ����
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
					//�������� ������� �� ������� ����������
					final_co.a = a;
					final_co.b = b;
					return final_co;
				}
			}
		}
	}
}


