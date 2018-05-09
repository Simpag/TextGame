#pragma once
#include "stdafx.h"

#include "Fighting.h"
#include "Menu_Stats.h"
#include "Challenge_Mode_Enemy_Vector.h"

void display_challenge_mode_menu(Character* _player) {
	int _input;
	bool didPlayerWin; //Store if the player won or not

	Enemy* _opponent = challenge_mode_enemy_vector.at(_player->get_challenge_mode_level());

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
			_player->increment_challenge_mode_level(); //Move to next enemy
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
		display_challenge_mode_menu(_player);
		break;
	}
}