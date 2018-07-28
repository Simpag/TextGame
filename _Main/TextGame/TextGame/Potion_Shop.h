#pragma once

#include "stdafx.h"

#include "Potion_Vector.h"

void display_potion_shop() {
	int _input;
	int _potion_vector_length = potion_vector.vector.size();

	for (int i = 0; i < _potion_vector_length; i++) {
		std::cout << "[" << i << "]" << " " << potion_vector.vector[i]->get_name() << " Cost: " << potion_vector.vector[i]->get_cost() << std::endl;
	}

	std::cout << "\n[" << _potion_vector_length << "] Back \n[n] Buy item \n";
	std::cin >> _input;
	if (_input == _potion_vector_length) {
		system("cls");
		display_shop_menu();
	}
	else if ((_input <= _potion_vector_length) && (_input >= 0)) {
		system("cls"); //Clean the terminal

					   /*
					   armor name
					   armor cost
					   effectiveness
					   */

					   //Print stats
		std::cout << "Do you want to buy " << potion_vector.vector[_input]->get_name() << " for " << potion_vector.vector[_input]->get_cost() << "?" << std::endl;
		std::cout << "Effectiveness: " << 100 * potion_vector.vector[_input]->get_effectiveness() << "%" << std::endl;
		std::cout << std::endl << "[0] Yes, [1] No" << std::endl;

		int _toBuy, _successful_purchase;
		std::cin >> _toBuy;
		if (_toBuy == 0) {
			_successful_purchase = buy_item(potion_vector.vector[_input], player.inventory, &player);
		}
		else {
			system("cls");
			display_potion_shop();
			return;
		}

		system("cls");
		if (_successful_purchase == 0) { //Successful
			std::cout << "Item was successfully purchased!\n";
		}
		else if (_successful_purchase == 1) { //Inventory full
			std::cout << "Inventory is full!\n";
		}
		else if (_successful_purchase == 2) {
			std::cout << "Not enough money! \n";
		}
		display_potion_shop();
	}
}