#include <iostream>
extern const int CHANGE_PLAYER;

#include <windows.h>
using namespace std;
////////// тут зібрані функції для відображення інформації та запитів /////////


//отримує від користувача номер категрії та повертає її
int ask(int q)
{					
	char tmp;
	do 
	{
		cout << "\t\t\t\tYour answer: ";
		cin >> tmp; 
	}
	while(tmp < '1' || tmp > q + '0');
	switch(tmp)
	{
		case '1':	return 1;	break;
		case '2': 	return 2;	break;
		case '3': 	return 3;	break;
		case '4':	return 4;	break;
		
		default:	cout<<"\nI don\'t work with numers bigger than 4!\n";
	}
}


/////////////pass time/////////////////
//створює полосу очікування
void pass_time(void)
{
	cout << endl;
	for (int i = CHANGE_PLAYER*2; i > 0; i--)
	{
		cout << "_";
	}
	cout <<endl;
	
	for(int i = CHANGE_PLAYER*2; i > 0; i--)
	{
		cout <<char(178);
		Sleep(500);
	}
	cout<< endl;
}


//////////////// шаблон таблиці ////////////////////


//міні функція яка друкує риски в таблиці
static void print(int amount)		
{									//отримує кі-сть штук і виводить їх на екран
	for(int i = 0; i < amount; i++)
	{
		cout << char(205);
	}
}


//виводим титульну сторінку для початку гри
//шаблон + 1 відділення для запитання і варіантів відповіді
//передаємо 4 строки, де 1 це запитання а решта можливі варіанти відповіді
void instruction(string title, string firstLine, string secondLine, string thirdLine)// довжина строки 59 символів(щоб відцентрувати)
{
	cout << "\n\n\n";
	
	cout << " " << char(201);
	print(10);
	cout << char(203);
	print(53);
	cout << char(203);
	print(10);
	cout << char(187);
	
	
	
	cout << "\n "<<char(186)<< "\t    "<< char(186)<<"\t\t\t\t\t\t\t  "<< char(186) << "\t     " << char(186);
	cout << "\n "<<char(186)<< "\t    "<< char(186)<<"\t\t     -This is a Battleship-\t\t  "<< char(186) << "\t     " << char(186);
	cout << "\n "<<char(186)<< "\t    "<< char(186)<<"\t  I won't tell you rules, i hope you know them\t  "<< char(186) << "\t     " << char(186);
	cout << "\n "<<char(186)<< "\t    "<< char(186)<<"\t\t\t\t\t\t\t  "<< char(186) << "\t     " << char(186)<<endl;
	
	cout <<" "<< char(204);
	print(7);
	cout << char(203);
	print(2);
	cout << char(202);
	print(53);
	cout << char(202);
	print(2);
	cout << char(203);
	print(7);
	cout << char(185);
	
	cout << "\n "<<char(186)<< "\t "<< char(186)<<"\t\t\t\t\t\t\t     "<< char(186) << "\t     " << char(186);
	cout << "\n "<<char(186)<< "\t "<< char(186)<<"\t\t\t\t\t\t\t     "<< char(186) << "\t     " << char(186);
	cout << "\n "<<char(186)<< "\t "<< char(186)<<"\t\t\t\t\t\t\t     "<< char(186) << "\t     " << char(186);
	cout << "\n "<<char(186)<< "\t "<< char(186)<<"\t\t               <<|                           "<< char(186) << "\t     " << char(186);
	cout << "\n "<<char(186)<< "\t "<< char(186)<<"\t\t                 |                           "<< char(186) << "\t     " << char(186);
	cout << "\n "<<char(186)<< "\t "<< char(186)<<"\t\t       __________|__________                 "<< char(186) << "\t     " << char(186);
	cout << "\n "<<char(186)<< "\t "<< char(186)<<"\t\t       \\ 0   0   0   0  0  /                 "<< char(186) << "\t     " << char(186);
	cout << "\n "<<char(186)<< "\t "<< char(186)<<"\t\t        \\                 /                  "<< char(186) << "\t     " << char(186);
	cout << "\n "<<char(186)<< "\t "<< char(186)<<"\t\t         \\_______________/                   "<< char(186) << "\t     " << char(186);
	cout << "\n "<<char(186)<< "\t "<< char(186)<<"\t\t\t\t\t\t\t     "<< char(186) << "\t     " << char(186);
	cout << "\n "<<char(186)<< "\t "<< char(186)<<"\t\t\t\t\t\t\t     "<< char(186) << "\t     " << char(186);
	cout << "\n "<<char(186)<< "\t "<< char(186)<<"\t\t\t\t\t\t\t     "<< char(186) << "\t     " << char(186);
	cout << "\n "<<char(186)<< "\t "<< char(186)<<"\t\t\t\t\t\t\t     "<< char(186) << "\t     " << char(186)<< endl;
	
	cout << " " << char(186) << "       ";
	cout << char(204);
	print(59);
	cout << char(185) << "       ";
	cout << char(186);
	
	cout << "\n "<<char(186)<< "\t "<< char(186)<<"\t\t\t\t\t\t\t     "<< char(186) << "\t     " << char(186);
	cout << "\n "<<char(186)<< "\t "<< char(186)<<"\t\t\t\t\t\t\t     "<< char(186) << "\t     " << char(186);
	cout << "\n "<<char(186)<< "\t "<< char(186)<<"\t\t\t\t\t\t\t     "<< char(186) << "\t     " << char(186);
	
	
	
	
	cout << "\n "<<char(186)<< "\t "<< char(186)<<title<< char(186) << "\t     " << char(186);
	
	cout << "\n "<<char(186)<< "\t "<< char(186)<<"\t\t\t\t\t\t\t     "<< char(186) << "\t     " << char(186);
	cout << "\n "<<char(186)<< "\t "<< char(186)<<"\t\t\t\t\t\t\t     "<< char(186) << "\t     " << char(186);
	
	cout << "\n "<<char(186)<< "\t "<< char(186)<<firstLine<< char(186) << "\t     " << char(186);
	
	cout << "\n "<<char(186)<< "\t "<< char(186)<<"\t\t\t\t\t\t\t     "<< char(186) << "\t     " << char(186);
	
	cout << "\n "<<char(186)<< "\t "<< char(186)<<secondLine<< char(186) << "\t     " << char(186);
	
	cout << "\n "<<char(186)<< "\t "<< char(186)<<"\t\t\t\t\t\t\t     "<< char(186) << "\t     " << char(186);
	
	cout << "\n "<<char(186)<< "\t "<< char(186)<<thirdLine<< char(186) << "\t     " << char(186);
	
	cout << "\n "<<char(186)<< "\t "<< char(186)<<"\t\t\t\t\t\t\t     "<< char(186) << "\t     " << char(186);
	cout << "\n "<<char(186)<< "\t "<< char(186)<<"\t\t\t\t\t\t\t     "<< char(186) << "\t     " << char(186);
	cout << "\n "<<char(186)<< "\t "<< char(186)<<"\t\t\t\t\t\t\t     "<< char(186) << "\t     " << char(186);
	cout << "\n "<<char(186)<< "\t "<< char(200);
	print(59);
	cout<< char(188) << "\t     " << char(186);
	cout << "\n "<<char(186)<< "\t  "<<"\t\t\t\t\t\t\t     "<<   "\t     " << char(186);
	cout << "\n "<<char(186)<< "\t  "<<"\t\t\t\t\t\t\t     "<<   "\t     " << char(186);
	cout << "\n "<<char(186)<< "\t  "<<"\t\t\t\t\t\t\t     "<<   "\t     " << char(186);
	
	
	cout << "\n "<<char(200);
	print(75);
	cout << char(188);
	
	cout << endl;
	
	}


