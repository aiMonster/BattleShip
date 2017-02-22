#include <iostream>
#include <windows.h> //��� ����������� �������� ������

#include "Field.h"

#include <cstdlib>//��� ���������� ������ 
#include <ctime>// ---//--- 
using namespace std;


//������������ ������ � ���
void Field::put_ships(bool who)//0 - yourself, 1 - random
{
	int d,temp; //��������, ����� ��� ����� �� ���������� ����� ������ ����������, �� ������� ���������� ���� �����
	CO cord;
	srand(static_cast<unsigned int>(time(0)));//�������� ������
	if(who)
	{
		//���� ��������, �� ���������� ����������� ��� �������
		system("cls");
		//cout << "\n\t\t\t adding ships...";
	}
	
	//������� 1 �������� �������� 4
	do//������ ����, ���� �������� �� ���� ����������� ���������
	{
		temp = 0;
		if(!who)
		{
			system ("cls"); //������ ����� �� ������ ��������
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
		//������� ���������
		temp = putting(d, 4, cord, 0);
	}
	while (temp != 1); //���� ����, ���� ����� �� ��������� �� ��������� ��������
	
	
	//��� ������� �������� 3, �� �� ���� 2
	for (int q = 0; q < 2; q++ )
	{
		do//������ ����, ���� �������� �� ���� ����������� ���������
		{
			temp = 0;
			if(!who)
			{
				system ("cls"); //������ ����� �� ������ ��������
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
	
	
	//��� 3 ������� �������� 2
	for (int q = 0; q < 3; q++ )
	{
		do//������ ����, ���� �������� �� ���� ����������� ���������
		{
			temp = 0;
			if(!who)
			{
				system ("cls"); //������ ����� �� ������ ��������
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
	
	
	//��� 4 ������� �������� 1
	for (int q = 0; q < 4; q++ )
	{
		do//������ ����, ���� �������� �� ���� ����������� ���������
		{
			temp = 0;
			if(!who)
			{
				system ("cls"); //������ ����� �� ������ ��������
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


/////////////////////// ��������� ///////////////////////////////////////

//������� �������� � �������� ����
bool Field ::putting(int dir, int len, CO cord, int numb)
{
	bool temp = 0;
	int f = cord.a;
	int s = cord.b;
	
	// ���� �������� 1
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
	
	
	//���� �������� 2
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
	
	
	//���� �������� 3
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
	
	//���� �������� 4
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
	
	return temp; //1 - �������� ������ ����������, 0 - ������� ���������
}


