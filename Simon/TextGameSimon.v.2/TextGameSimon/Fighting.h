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
	int _coin = rand() % 2;
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
			system("cls");
			display_fight(_character, _opponent);
			std::cin >> _input;
			Sleep(1 * 1000);
			system("cls");
			_character->perform_attack(_opponent, _input);
			Sleep(4 * 1000);
		}
		else {
			system("cls");
			_opponent_attack = rand() % 3;

			switch (_opponent_attack) {
			case 0:
				std::cout << "Opponent performed an basic attack! \n";
				break;
			case 1:
				std::cout << "Opponent performed an quick attack! \n";
				break;
			case 2:
				std::cout << "Opponent performed an strong attack! \n";
				break;
			}

			_opponent->perform_attack(_character, _opponent_attack);
			Sleep(4*1000); 
		}
		
		//Check if anyone won
		if (_character->get_health() < 0) {
			didPlayerWin = false;
			isOver = true;
		}
		else if (_opponent->get_health() < 0) {
			didPlayerWin = true;
			isOver = true;
		}

		isPlayer = !isPlayer; //End turn
	}

	_character->set_health(_character->get_max_health());

	return didPlayerWin;
}

void display_fight(Character* _character, Character* _opponent) {
	std::cout << "Your health: " << _character->get_health() << "\nEnemy health: " << _opponent->get_health();
	std::cout << "\n[0] Basic Attack \n[1] Quick Attack \n[2] Strong Attack \n";
}