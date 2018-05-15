#pragma once
#include "stdafx.h"

#include "Fighting.h"
#include "Menu_Stats.h"

/*
Show player enemy level and stats
Ask the player to enter arena or leave
If enter goto fighting logic
Else if leave goto main logic
*/

void display_training_menu(Character* _player) {
	int _input;
	bool didPlayerWin;

	Enemy* _opponent = new Enemy("Test opponent", 20, 20, 20, 0.3, 0.3, 0, 0.3, 500);

	std::cout << "Do you want to fight against " << _opponent->get_name() << "?\n";
	display_stats(_opponent, false);
	std::cout << "[0] Enter fight \n[1] Back \n";
	std::cin >> _input;

	switch (_input) {
	case 0: 
		system("cls");
		didPlayerWin = fight(&player, _opponent); //Fight
		system("cls");
		if (didPlayerWin) {
			std::cout << "You won! \n";
			_player->add_money(_opponent->get_worth());
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
		display_training_menu(_player);
		break;
	}
}