#pragma once
#include "stdafx.h"

void display_fight(Character* _character, Character* _opponent);

/*
Flip a coin to decide who starts
Player attack menu
0: Basic attack
1: Quick attack
2: Strong attack
Enemy randomly picks attack
*/

bool fight(Character* _character, Character* _opponent) {
	int _input, _opponent_attack;
	int _coin = rand() % 2; //Random number between 0 and 1 (coin flip)
	bool isPlayer, didPlayerWin;
	bool isOver = false;

	switch (_coin) {
	case 0:
		std::cout << "You start! \n";
		isPlayer = true;
		Sleep(1 * 1000); //millisecond
		break;

	case 1:
		std::cout << "Opponent starts! \n";
		isPlayer = false;
		Sleep(1 * 1000);
		break;
	}

	while (!isOver) {
		if (isPlayer) {
			do { 
				system("cls");
				display_fight(_character, _opponent);
				std::cin >> _input; 
			} while (!(_input < 3) && !(_input >= 0));
			Sleep(1 * 1000);
			system("cls");
			switch (_input) {
			case 0:
				_character->perform_attack(_opponent, Basic_Attack);
				break;

			case 1:
				_character->perform_attack(_opponent, Quick_Attack);
				break;

			case 2:
				_character->perform_attack(_opponent, Strong_Attack);
				break;
			}
			Sleep(4 * 1000);
		}
		else {
			system("cls");
			_opponent_attack = rand() % 3;

			switch (_opponent_attack) {
			case 0:
				std::cout << "Opponent performed an basic attack! \n";
				_opponent->perform_attack(_character, Basic_Attack);
				break;
			case 1:
				std::cout << "Opponent performed an quick attack! \n";
				_opponent->perform_attack(_character, Quick_Attack);
				break;
			case 2:
				std::cout << "Opponent performed an strong attack! \n";
				_opponent->perform_attack(_character, Strong_Attack);
				break;
			}
			Sleep(4*1000); 
		}
		
		//Check if anyone won
		if (_character->get_health() < 0) { //Is the player dead
			didPlayerWin = false;
			isOver = true;
		}
		else if (_opponent->get_health() < 0) { //Is the opponent dead
			didPlayerWin = true;
			isOver = true;
		}

		isPlayer = !isPlayer; //End turn
	}

	_character->add_health(_character->get_max_health()); //Restore player health after match

	return didPlayerWin;
}

void display_fight(Character* _character, Character* _opponent) {
	std::cout << "Your health: " << _character->get_health() << "\nEnemy health: " << _opponent->get_health();
	std::cout << "\n[0] Basic Attack \n[1] Quick Attack \n[2] Strong Attack \n";
}