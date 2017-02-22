#include <iostream>
using namespace std;
// �������� � main
extern const char WATER;
extern const char SHIP;
extern const char DEAD_SHIP;
extern const char EMPTY;
extern const int ACTION_RESULT;


////////////////////////////// ������ ������� //////////////////////////

			    //���������/1 ������/2 ������/3 ������ (�� ����'������)
void instruction(string, string, string, string thirdLine = "\t\t\t\t\t\t\t     "); // �������� �������� �������
//������� ���� ������ �� ���� 59 ������� ��� ��� ������������

int ask(int);//������� ��� ����������� ������� (������ ����������� ���� ������� 1-4) 


//��������� ��� ���������� ��������� ���� ������ �������
struct Coordinate
{
	int a;
	int b;
	bool alive; //yes - 1, no - 0
};
typedef Coordinate CO; //��� �������� ������������ ���������

void pass_time(void); //���� ����������

///////////////////////// class Ship ///////////////////////////////////////////////////
class Ship
{
	private:
		int length; //������� �������
		CO ship[4]; //����� ��������� ��������� � ������������ ������� � 4 ������
		
	public:
		
		CO help(int); //������� ���������� �-� ������ �������
		int get_length();//������� �������
		
		void set_length(int); //��� ������������ ������� �� �����. (��� ������������ ����)
		
		//������ ���������� ������� �� ������� 
		void set_coordinate(int, CO); //������, ����������
		
		//�������� ���� ������� (��������� - 2, ������ - 0, ����� -1)
		int ship_state() const ; 
		
		//�������� �� �������� ���� ���������� ������ �������
		int belong(CO); // 1- ��� (�������� ��� �����), 0 - �
};



