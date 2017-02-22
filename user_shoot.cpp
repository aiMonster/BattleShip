#include <iostream>
#include <windows.h>
#include "Field.h"
using namespace std;

//������ ������
bool Field::shoot(Field* opponent)//������ ��'��� � ���� ��������� ������
{
	CO target = ask_co();//�������� ���������� 
	int answer = opponent->belong(target, this); //��������� �� �������, ��������, ����� //���� ����� ������� ������� ���������
	bool return_value;
	//���� ������� ��� ��������
	if(answer == 1 || answer == 2)
	{
		switch(answer)
		{
			case 1: cout << "\n\t\t\t YOU KILLED ME"; break;
			case 2: cout << "\n\t\t\t YOU INJURED ME"; break;
		}
		Sleep(ACTION_RESULT);
		opponent->change_my_to(1, target); //������ ������ � ���������
		change_op_to(1, target); //�� � ���� �� ���
		return 1;//��������� 1 ��� ���� ������ �� ������ �����
	}
	else if(answer == 3 || element(target) == EMPTY)
	{
		//���� �� ��� ������ � �� ���� �� ������� ���� 2 ����
		cout << "\n\t\t   THIS COORDINATE ALREADY WAS!";
		Sleep(ACTION_RESULT);
		return 1;
	}
	else
	{
		cout << "\n\t\t\t AH-AH-AH LOSER";
		Sleep(ACTION_RESULT);
		opponent->change_my_to(0, target);//������ ������ � ���������
		change_op_to(0, target);//�� � ���� �� ���
		return 0;
	}
}


