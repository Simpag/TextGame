#pragma once

#include "stdafx.h"

#include "Weapon_Vector.h"
#include "Shop.h"

int buy_item(Item* _item_to_buy, Inventory* _inventory);
void display_shop_menu();

//string _name, int _cost, ItemType _type, int _damage, double _crit_chance, double _accuracy

void display_weapon_shop() {
	int _input;
	int _weapon_vector_length = weapon_vector.size();
	
	for (int i = 0; i < _weapon_vector_length; i++) {
		std::cout << "[" << i << "]" << " " << weapon_vector[i]->get_name() << " Cost: " << weapon_vector[i]->get_cost() << std::endl;
	}

	std::cout << "\n[" << _weapon_vector_length << "] Back [n] Buy item \n";
	std::cin >> _input;
	if (_input == _weapon_vector_length) {
		system("cls");
		display_shop_menu();
	}
	else if ((_input <= _weapon_vector_length) && (_input >= 0)) {
		system("cls"); //Clean the terminal

		/*
		weapon name
		weapon cost
		weapon damage
		weapon crit chance
		weapon accuracy
		*/

		//Print stats
		std::cout << "Do you want to buy " << weapon_vector[_input]->get_name() << " for " << weapon_vector[_input]->get_cost() << "?" << std::endl;
		std::cout << "Accuracy: " << weapon_vector[_input]->get_accuracy() << std::endl;
		std::cout << "Crit Chance: " << weapon_vector[_input]->get_crit_chance() << std::endl;
		std::cout << std::endl << "[0] Yes, [1] No" << std::endl;

		int _toBuy, _successful_purchase;
		std::cin >> _toBuy;
		if (_toBuy == 0) {
			_successful_purchase = buy_item(weapon_vector[_input], test.inventory);
		}
		else {
			system("cls");
			display_weapon_shop();
			return;
		}

		system("cls");
		if (_successful_purchase == 0) { //Successful
			std::cout << "Item was successfully purchased!\n";
		}
		else if (_successful_purchase == 1) { //Inventory full
			std::cout << "Inventory is full!\n";
		}
		display_weapon_shop();
	}
}