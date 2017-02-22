#include <iostream>
#include <process.h> //��� exit(0) � ��� ������� �����
#include "Ship.h" //�������� ������� �������
using namespace std;
static void check_length(int c, int l); //�������� ������� ��� �������� �� �� ����������� ������� �������� ������


//������ ���������� ������� �� ������� 
void Ship::set_coordinate(int cell, CO cell_co)//���������� ����� ������, ���������� ������
{
	check_length(cell, length);//���������� �� �� �� �������� �� ���
	ship[cell] = cell_co; //���������� ���������� 
	ship[cell].alive = 1; //����� �� ������������ ������ ����� (�� ���������)
}


//������ ������� ��������		
void Ship::set_length(int l)
{
	length = l;
}


//�������� ���� ������� (��������� - 2, ������ - 0, ����� - 1)
int Ship :: ship_state() const
{
	
	int temp_injured = 0;
	for(int i = 0; i < length; i++)
	{
		if(ship[i].alive == 0)
		{
			temp_injured++; //���� ��� ����� ������ ==0, ������� ���������
		}
	}
			
	if(temp_injured == 0)
	{
		return 1; //���� �����
	}
	else if (temp_injured == length) //���� ������� �������� == ������, ������� �����
	{
		return 0; //���� �����
	}
	else
		return 2;
	
}


//������� ���������� //������ ����� ������
CO Ship :: help (int n)
{
	return ship[n];
}


//������� ������� ������ �������
int Ship :: get_length()
{
	return length;
}
	
		
//�������� �� �������� ���� ���������� ������ ������� �� ���� �� � ��� ���������
// 0 - ����, 1 - �������� ��� �����
int Ship :: belong(CO hit) //������ �������� ���������� ��� ��������
{
	int live = 0;
	for(int i = 0; i < length; i++) //�������� ����� ���������� ������ �������
	{
		if (hit.a == ship[i].a && hit.b == ship[i].b)
		{
			if(ship[i].alive == 0) return 3; //This coordinate was
			
			ship[i].alive = 0;
			return 1; //�������� ��� �����
		}
	}
	return 0; //���� �
}
		

//////////////////////////////////////////////////////////////////////////
//������� ��� �������� �� �� �� ������ �� ��� ������� �������
static void check_length(int c, int l) //����� ������, ������� �������
{
	if(c >= l)
	{
		cout << "\n You made bad thing!\n";
		exit(0);
	}
}


