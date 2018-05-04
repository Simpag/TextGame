#pragma once

#include "stdafx.h"

#include "Armor_Vector.h"
#include "Menu_Shop.h"

void display_armor_shop() {
	int _input;
	int _armor_vector_length = armor_vector.size();

	for (int i = 0; i < _armor_vector_length; i++) {
		std::cout << "[" << i << "]" << " " << armor_vector[i]->get_name() << " Cost: " << armor_vector[i]->get_cost() << std::endl;
	}

	std::cout << "\n[" << _armor_vector_length << "] Back \n[n] Buy item \n";
	std::cin >> _input;
	if (_input == _armor_vector_length) {
		system("cls");
		display_shop_menu();
	}
	else if ((_input <= _armor_vector_length) && (_input >= 0)) {
		system("cls"); //Clean the terminal

					   /*
					   armor name
					   armor cost
					   damage_reduction
					   accuracy
					   deflect_chance
					   health_boost
					   */

					   //Print stats
		std::cout << "Do you want to buy " << armor_vector[_input]->get_name() << " for " << armor_vector[_input]->get_cost() << "?" << std::endl;
		std::cout << "Damage reduction: " << 100*armor_vector[_input]->get_damage_reduction() << "%" << std::endl;
		std::cout << "Accuracy: " << 100*armor_vector[_input]->get_accuracy() << "%" << std::endl;
		std::cout << "Deflect chance: " << 100*armor_vector[_input]->get_deflect_chance() << "%" << std::endl;
		std::cout << "Health boost: " << 100*armor_vector[_input]->get_health_boost() << "%" << std::endl;
		std::cout << std::endl << "[0] Yes, [1] No" << std::endl;

		int _toBuy, _successful_purchase;
		std::cin >> _toBuy;
		if (_toBuy == 0) {
			_successful_purchase = buy_item(armor_vector[_input], test.inventory, &test);
		}
		else {
			system("cls");
			display_armor_shop();
			return;
		}

		system("cls");
		if (_successful_purchase == 0) { //Successful
			std::cout << "Item was successfully purchased!\n";
		}
		else if (_successful_purchase == 1) { //Inventory full
			std::cout << "Inventory is full!\n";
		}
		display_armor_shop();
	}
}