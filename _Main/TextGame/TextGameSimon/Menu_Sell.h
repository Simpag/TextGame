#pragma once

#include "stdafx.h"
#include "Item_Functions.h"

void display_sell(Inventory* _inventory, Character* _player) {
	int _input;
	int _inventory_size = _inventory->get_inventory_size();

	if (_inventory_size == 0) {
		std::cout << "Nothing to sell! \n";
	}
	else {
		for (int i = 0; i < _inventory_size; i++) {
			std::cout << "Slot [" << i + 1 << "/" << "10" << "]: " << _inventory->get_name(i) << "'s value is: " << _inventory->get_item(i)->get_worth() << " ID: " << i << std::endl;
		}
	}

	std::cout << "[n] Enter ID to sell \n" << "[" << _inventory_size << "] Back \n";
	std::cin >> _input;

	if (_input == _inventory_size) { //Back
		system("cls");
		display_shop_menu();
	}
	else if (_input < _inventory_size && _input >= 0) { //Sell item
		system("cls");
		int _to_sell;

		std::cout << "Are you sure you want to sell " << _inventory->get_name(_input) << " for " << _inventory->get_item(_input)->get_worth() << " ? \n" <<
			"[0] Yes \n[1] No\n";
		std::cin >> _to_sell;
		
		if (_to_sell == 0) { //If the user wants to sell the item
			sell_item(_inventory->get_item(_input), _inventory, _player);
			system("cls");
			std::cout << "Item successfully sold!\n";
			display_sell(_inventory, _player);
		}
		else {
			display_sell(_inventory, _player);
		}
	}
	else {	//If the user doesnt input a matching number
		system("cls");
		display_sell(_inventory, _player);
	}
}