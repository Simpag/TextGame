#pragma once
#include "stdafx.h"

void display_fight(Character* _character, Character* _opponent, bool _got_potion);

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
	int _delay_between_text = 3;
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
			if (_character->equipment_inventory->get_got_potion()) {
				do {
					system("cls");
					display_fight(_character, _opponent, true);
					std::cin >> _input;
				} while (!(_input <= 3) && !(_input >= 0));
			}
			else {
				do {
					system("cls");
					display_fight(_character, _opponent, false);
					std::cin >> _input;
				} while (!(_input <= 2) && !(_input >= 0));
			}
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

			case 3:
				_character->use_potion();
				break;
			}
			Sleep(_delay_between_text * 1000);
		}
		else {
			system("cls");
			_opponent_attack = rand() % 3;

			switch (_opponent_attack) {
			case 0:
				std::cout << _opponent->get_name() << " performed an basic attack! \n";
				Sleep(_delay_between_text * 1000);
				system("cls");
				_opponent->perform_attack(_character, Basic_Attack);
				break;
			case 1:
				std::cout << _opponent->get_name() << " performed an quick attack! \n";
				Sleep(_delay_between_text * 1000);
				system("cls");
				_opponent->perform_attack(_character, Quick_Attack);
				break;
			case 2:
				std::cout << _opponent->get_name() << " performed an strong attack! \n";
				Sleep(_delay_between_text * 1000);
				system("cls");
				_opponent->perform_attack(_character, Strong_Attack);
				break;
			}
			Sleep(_delay_between_text * 1000);
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

void display_fight(Character* _character, Character* _opponent, bool _got_potion) {
	if (_got_potion) {
		std::cout << "Your health: " << _character->get_health() << "\nEnemy health: " << _opponent->get_health();
		std::cout << "\n[0] Basic Attack \n[1] Quick Attack \n[2] Strong Attack \n[3] Use Potion \n";
	}
	else {
		std::cout << "Your health: " << _character->get_health() << "\nEnemy health: " << _opponent->get_health();
		std::cout << "\n[0] Basic Attack \n[1] Quick Attack \n[2] Strong Attack \n";
	}
}