#pragma once
#include "stdafx.h"
#include "Character.h"

void display_stats(Character* _character) {
	int _input;

	std::cout << "Money: " << _character->get_money() << std::endl;
	std::cout << "Health: " << _character->get_health() << std::endl;
	std::cout << "Damage: " << _character->get_damage() << std::endl;
	std::cout << "Damage Reduction: " << _character->get_damage_reduction() * 100 << std::endl;
	std::cout << "Accuracy: " << _character->get_accuracy() * 100 << std::endl;
	std::cout << "Deflect Chance: " << _character->get_deflect_chance() * 100 << std::endl;
	std::cout << "Crit Chance: " << _character->get_crit_chance() * 100 << std::endl;

	std::cout << std::endl << "[0] Back\n";
	std::cin >> _input;

	system("cls");
}