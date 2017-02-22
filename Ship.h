#include <iostream>
using namespace std;
// Дивитись в main
extern const char WATER;
extern const char SHIP;
extern const char DEAD_SHIP;
extern const char EMPTY;
extern const int ACTION_RESULT;


////////////////////////////// зовнішні функції //////////////////////////

			    //запитання/1 варіант/2 варіант/3 варант (не обов'язково)
void instruction(string, string, string, string thirdLine = "\t\t\t\t\t\t\t     "); // виводить титульну сторінку
//довжина однієї строки має бути 59 символів щоб все відобразилось

int ask(int);//функція для запитування категорії (приймає максимальну можл відповідь 1-4) 


//Структура для збереження координат однієї ячейки корабля
struct Coordinate
{
	int a;
	int b;
	bool alive; //yes - 1, no - 0
};
typedef Coordinate CO; //для зручності використання структури

void pass_time(void); //імітує очікування

///////////////////////// class Ship ///////////////////////////////////////////////////
class Ship
{
	private:
		int length; //довжина корабля
		CO ship[4]; //масив структури координат з максимальним розміром в 4 палуби
		
	public:
		
		CO help(int); //повертає координати і-ої ячейки корабля
		int get_length();//повертає довжину
		
		void set_length(int); //для встановлення довжини за умовч. (для конструктора поля)
		
		//задаємо координати корабля по ячейках 
		void set_coordinate(int, CO); //ячейка, координата
		
		//перевіряє стан корабля (поранений - 2, вбитий - 0, цілий -1)
		int ship_state() const ; 
		
		//перевіряє чи належить дана координата нашому кораблю
		int belong(CO); // 1- так (поранено або вбито), 0 - ні
};



