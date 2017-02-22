#include <iostream>
#include <windows.h> //для періодичного очищення екрану
#include "Field.h"
#include <cstring>
using namespace std;

//вибираємо вигляд: 
extern const char WATER = '~'; //води (пусті клітинки)
extern const char SHIP = 'O'; //кораблі
extern const char DEAD_SHIP = 'X'; //поранені частини
extern const char EMPTY = ' ';//клітинки мимо

//вибираємо відліки часу
extern const int ACTION_RESULT = 2000;
extern const int CHANGE_PLAYER = 5;



int main(int argc, char** argv)
{
	system("color B0"); //змінюємо фон терміналу
	instruction("\t\t    Just choose mode of a game:              ",
	             "\t1 - Play with another player on the same computer    ",
	             "\t\t    2 - Play against computer                ",
	             "   3 - Only you play, and computer counts times you spent  ");
	int answer = ask(3);
	
	////////// two players on the same computer ////////////////////////////
	if(answer == 1)
	{
		//створюємо гравців
		Field player_1;
		Field player_2;
		string name_1, name_2; //тут будутьїх імена
		
		//отримуємо ім'я та розставляєм кораблі
		cout<< "\n\tPLAYER 1 - ENTER YOUR NAME: ";
		cin >> name_1;
		system("cls");
		instruction("                How do you want to put ships:              ",
					"                        1 - Random                         ", 
					"                      2 - On your own                      ");
		answer = ask(2);
		switch(answer)
		{
			case 1:		player_1.put_ships(1); 	break;
			case 2:		player_1.put_ships(0); 	break;
		}
		player_1.display(1);
		pass_time();
		 // 
		system("cls");
		cout << "\n\tCHANGING TO PLAYER 2";
		pass_time();
		// те ж з гравцем 2
		system("cls");
		cout<< "\n\tPLAYER 2 - ENTER YOUR NAME: ";
		cin >> name_2;
		system("cls");
		instruction("                How do you want to put ships:              ",
					"                        1 - Random                         ", 
					"                      2 - On your own                      ");
		answer = ask(2);
		switch(answer)
		{
			case 1:		player_2.put_ships(1); 	break;
			case 2:		player_2.put_ships(0); 	break;
		}
		////////////////////////////////////////////////////////////////
		int winner;
		int next_1 = 1;
		int next_2 = 1;
		while(true)
		{
			while(next_2)
			{
				if(player_1.is_alive() == 0)
				{
					winner = 0;
					goto s_finish;
				}
				system("cls");
				cout << "\n\t\t\tYOUR SHOT - " << name_2 << endl;
				player_2.display(1);
				player_2.display(2);
				next_2 = player_2.shoot(&player_1);
			}
			
			system("cls");
			cout << "\n\tCHANGING MEMBER FROM " << name_2 << " TO " << name_1;
			pass_time();
			
			while(next_1)
			{
				if(player_2.is_alive() == 0)
				{
					winner = 1;
					goto s_finish;
				}
				system("cls");
				cout << "\n\t\t\tYOUR SHOT - " << name_1 << endl;
				player_1.display(1);
				player_1.display(2);
				next_1 = player_1.shoot(&player_2);
			}
			
			system("cls");
			cout << "\n\tCHANGING MEMBER FROM " << name_1 << " TO " << name_2;
			pass_time();
			
			next_1 = next_2 = 1;
			
		}
		s_finish:
			if(winner == 0)
			{
				system("cls");
				cout << "\n\n\n\t     YOU WON, " << name_2;
				cout << "\n\n\n\t\t     YOU WON, " << name_2;
				cout << "\n\n\n\t\t\t     YOU WON, " << name_2;
				cout << "\n\n\t\t\t YOUR FIELD FOR " <<name_1<<": ";
				player_2.display(1);
			}
			else if(winner == 1)
			{
				system("cls");
				cout << "\n\n\n\t     YOU WON, " << name_1;
				cout << "\n\n\n\t\t     YOU WON, " << name_1;
				cout << "\n\n\n\t\t\t     YOU WON, " << name_1;
				cout << "\n\n\t\t\t YOUR FIELD FOR " <<name_2<<": ";
				player_1.display(1);
			}
		
	}
	/////////////////// game with computer //////////////////////////////
	else if(answer == 2)
	{
		//створюємо гравців
		Field player;
		Field computer;
		
		//розставляєм кораблі
		computer.put_ships(1);
		//computer.display(1); читерство
		//pass_time();
		system("cls");
		instruction("                How do you want to put ships:              ",
					"                        1 - Random                         ", 
					"                      2 - On your own                      ");
		answer = ask(2);
		switch(answer)
		{
			case 1:		player.put_ships(1); 	break;
			case 2:		player.put_ships(0); 	break;
		}
				
		int winner;
		int next_c = 1;
		int next_u = 1;
		while(true)
		{
			while(next_u)
			{
				if(computer.is_alive() == 0)//якщо виграв йдем до мітки фініш
				{
					winner = 0;
					goto finish;
				}
				system("cls");
				cout << "\n\t\t\t    YOUR SHOT\n";
				player.display(1); //виводим поля
				player.display(2);
				next_u = player.shoot(&computer); //стріляєм
			}
			
			while(next_c)
			{
				if(player.is_alive() == 0)
				{
					winner = 1;
					goto finish;
				}
				system("cls");
				cout << "\n\t\t\t  COMPUTER SHOT\n";
				player.display(1);
				player.display(2);
				next_c = computer.rand_shot(&player);
			}
			
			next_u = next_c = 1;
		}
		finish:
		
		//вітаємо переможця
		if(winner == 0)
		{
			system("cls");
			cout << "\n\n\n\t     YOU WON";
			cout << "\n\n\n\t\t     YOU WON";
			cout << "\n\n\n\t\t\t     YOU WON";
			
		}
		else if(winner == 1)
		{
			system("cls");
			cout << "\n\n\n\t     YOU LOST";
			cout << "\n\n\n\t\t     YOU LOST";
			cout << "\n\n\n\t\t\t     YOU LOST";
			cout << "\n\n\t\t\t COMPUTER'S FIELD: ";
			computer.display(1);
		}
		
	}
	////////////////////// one player //////////////////////////////////////
	else if(answer == 3)
	{
		Field player;
		Field computer;
		
		int shots = 0;
		computer.put_ships(1);
		//computer.display(1); //читерство
		//Sleep(3000);
		int last_shot;
		
		do
		{
			system("cls");
			cout << "\n\t\t   You already made " << shots << " shots" << endl;
			player.display(2);
			last_shot = player.shoot(&computer);
			//last_shot = player.rand_shot(&computer); //так постріли буде робити комп'ютер
			if(!last_shot)
			{
				shots++;
			}
		}
		while(computer.is_alive() != 0);
		
		system("cls");
		cout << "\n\t\t   You already made " << shots << " shots" << endl;
		player.display(2);
		
		cout << "\n\n\n\t\t\t     YOU WON";
		cout << "\n\t\t       AND DID IT IN " << shots << " SHOTS";
	}
		
	return 0;
}



