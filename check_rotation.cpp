#include "Field.h"


//������� �� ����� ��������� �������� ������� size � �������� direction � ���������� ����������� coordinate
bool Field::check_rotation(int size, int direction, CO coordinate)
{
	int temp; // ���� 1 �� �����, ���� 0 �� �
	int d = direction;
	int f = coordinate.a; //f - first coordinate
	int s = coordinate.b; //s - second coordinate

	//���������� � ��������� �� ��������
	// �������� 1(����)
	if (d == 1)
	{
		temp = 1;
		for(int a = f - 1; a <= f + 1; a++)
		{
			for(int b = s - size; b <= s + 1; b++)
			{
				if(my_field[a][b] != WATER)
				{
					temp = 0; // ���� ����� ������� �� ������� ������� �������� �� �������� ��� ��� ���� �� ����
				}
			}
		}
		return temp; //���� �������� ����� ������� �������� 1
	}
	
	//�������� 2
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
	
	//�������� 3
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
	
	//�������� 4
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


