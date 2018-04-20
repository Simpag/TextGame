#pragma once

#include "stdafx.h"
#include "iostream"
#include "vector"

#include "Weapon_Vector.h"
#include "Item_Functions.h"

//string _name, int _cost, ItemType _type, int _damage, double _crit_chance, double _accuracy

void display_weapon_shop() {
	int _selection;
	int weapon_vector_length = weapon_vector.size();
	
	for (int i = 0; i < weapon_vector_length; i++) {
		std::cout << "[" << i << "]" << " " << weapon_vector[i]->get_name() << " Cost: " << weapon_vector[i]->get_cost() << std::endl;
	}

	std::cin >> _selection;
	if ((_selection <= weapon_vector_length - 1) && (_selection >= 0)) {
		system("cls"); //Clean the terminal
		
		/*
		weapon name
		weapon cost
		weapon damage
		weapon crit chance
		weapon accuracy
		*/

		//Print stats
		std::cout << "Do you want to buy " << weapon_vector[_selection]->get_name() << " for " << weapon_vector[_selection]->get_cost() << "?" << std::endl;
		std::cout << "Stats:" << std::endl << "Damage: " << weapon_vector[_selection]->get_damage() << std::endl;
		std::cout << "Accuracy: " << weapon_vector[_selection]->get_accuracy() << std::endl;
		std::cout << "Crit Chance: " << weapon_vector[_selection]->get_crit_chance() << std::endl;
		std::cout << std::endl << "[0] Yes, [1] No" << std::endl;

		int _toBuy, _successful_purchase;
		std::cin >> _toBuy;
		if (_toBuy == 0) {
			_successful_purchase = buy_item(weapon_vector[_selection]);
		}
		else {
			system("cls");
			return;
		}

		system("cls");
		if (_successful_purchase == 0) { //Successful
			std::cout << "Item was successfully purchased!\n";
		}
		else if (_successful_purchase == 1) { //Inventory full
			std::cout << "Inventory is full!\n";
			display_weapon_shop();
		}
	}
}