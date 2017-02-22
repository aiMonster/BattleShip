#include <iostream>
#include "Field.h"
using namespace std;



static void print(int amount)		//�� ������� ��� ����� ����� � �������
{									//������ �-��� ���� � �������� �� �� �����
	for(int i = 0; i < amount; i++)	// for display function
	{
		cout << char(205);
	}
}


//����������� ��� ����������� ����
Field_Sample::Field_Sample()
{
	//������� ��� ��������� ������ ��������
	for(int a = 0; a < 18; a++)
	{
		for(int b = 0; b < 18; b++)
		{
			my_field[a][b] = SHIP;
			opponent_field[a][b] = SHIP;
		}
	} 
  		
  	//������ ������� ��� �����������
	for(int a = 3; a < 15; a++)
	{
		for(int b = 3; b < 15; b++)
		{
			my_field[a][b] = WATER;
			opponent_field[a][b] = WATER;
		}
	}
}
	
	
//������� ��� ����������� ���� �� �����
void Field_Sample::display(int wh) const //1-my_field, 2-opponent_field
{	
	cout << endl << endl;
	cout<< "\t      "<<char(201);
	print(3);
	cout<<  char(203);
	print(31);
	cout << char(187) <<endl;
	cout<< "\t      "<< char(186)<< "   " <<  char(186)<< "  q  w  e  r  t  y  u  i  o  p " << char(186); //������� ����� ����������
	
	cout << endl<< "\t      " <<char(204);
	print(3);
	cout << char(206);
	print(31);
	cout << char(185);

	for(int a = 4; a < 14; a++)//
	{
		cout << endl<<  "\t      " << char(186)<< "   " << char(186) <<"\t\t\t\t  "<< char(186) << endl;
		cout <<"\t      " << char(186) << " " << a - 4 << " " << char(186); //�������� ���� �������� � ����������
		
		for(int b = 4; b < 14; b++)//
		{
			if(wh == 1)
				cout << "  " <<  my_field[a][b];// �������� ����� ������ ������ 
			
			else if(wh == 2)
				cout << "  " <<  opponent_field[a][b];// �������� ����� ������ ������
		}
		cout << " " << char(186);	
	}
	
	cout << endl<< "\t      " <<char(200);
	print(3);
	cout << char(202);
	print(31);
	cout << char(188);
}
		
			
//����������� �� ���� ������� ������� � ���� �������
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
	
	
//������ � ����������� ���������� �� ������� �� � ������ ���������  	
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


//������� �������� �� ��������������� ��� ��� 
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


//������� �������� �� ��� ��� � �������
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


//������� ������ ������� ����
char Field_Sample :: element (CO cor)
{
	return opponent_field[cor.a][cor.b];
}
	
	
//����� �������� ������� �������	
void Field :: surround (Ship ship, Field* opp)	
{
	//������� ������ ���� ������ �����
	for(int i = 0; i < ship.get_length(); i++)
	{
		CO tmp = ship.help(i); //�������� ���������� �-� ������ ������ �������
		CO tmp_2;
		//������� ����� ������� �������� ���� �� = ���
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


//�������� �� �������� ���������� ������� �� �������
//1 - ���� ��������
int Field::belong(CO hit, Field* opp)
{	
	int result;
	//�������� 4 ���������
	for(int i = 0; i < 4; i++)
	{
		result = deck_1[i].belong(hit);
		if(result == 3) return 3;
		else if(result == 1)
		{
			if(deck_1[i].ship_state() == 0) 
			{
				surround(deck_1[i], opp);
				//�������� �����, � ���� ���� ������� ������� ������� �������
				return 1;
			}
			else 
			{
				return 2;
			}
		}
	}
	
	//3 ���������
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
	
	//2 ���������
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
	
	//�������������
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
	
	//���� �� �������� �������
	return 0;
}


//�������� �� ���������� �� ��� ������
//���� 0 - �� �� ����� �������
bool Field::is_alive(void) const
{
	//�������� 4 ���������
	for(int i = 0; i < 4; i++)
	{
		if(deck_1[i].ship_state())
			return 1;
	}
	
	//3 ���������
	for(int i = 0; i < 3; i++)
	{
		if(deck_2[i].ship_state())
			return 1;
	}
	
	//2 ���������
	for (int i = 0; i < 2; i++)
	{
		if(deck_3[i].ship_state())
			return 1;
	}
	
	//�������������
	if(deck_4.ship_state())
		return 1;
	
	return 0;
}
		

//�������� �� �������� ������, ����� � �� �� ������� �����������		
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


