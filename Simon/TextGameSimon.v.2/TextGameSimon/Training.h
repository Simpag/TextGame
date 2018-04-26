#pragma once
#include "stdafx.h"

#include "Fighting.h"

/*
Show player enemy level and stats
Ask the player to enter arena or leave
If enter goto fighting logic
Else if leave goto main logic
*/

void display_training_menu() {
	int _input;
	bool didPlayerWin;

	Enemy* _enemy = new Enemy("Test opponent", 20);

	std::cout << "Do you want to fight against: " << _enemy->get_name() << " with " << _enemy->get_health() << " health? \n";
	std::cout << "[0] Enter fight \n[1] Back \n";
	std::cin >> _input;

	switch (_input) {
	case 0: 
		system("cls");
		didPlayerWin = fight(&test, _enemy);
		system("cls");
		if (didPlayerWin) {
			std::cout << "You won! \n";
		}
		else {
			std::cout << "Opponent won! \n";
		}

		display_arena_menu();
		break;
		
	case 1:
		system("cls");
		display_arena_menu();
		break;

	default:
		display_training_menu();
		break;
	}
}