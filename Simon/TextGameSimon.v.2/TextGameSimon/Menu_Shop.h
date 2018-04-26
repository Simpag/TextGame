#pragma once

#include "stdafx.h"

#include "Weapon_Shop.h"
#include "Armor_Shop.h"
#include "Potion_Shop.h"


void display_shop_menu() {
	int _state;

	std::cout << "[0] Weapon \n[1] Armor \n[2] Potions \n[3] Back \n";
	std::cin >> _state;

	switch (_state) {
	case 0:
		system("cls");
		display_weapon_shop();
		break;
	case 1:
		system("cls");
		display_armor_shop();
		break;
	case 2:
		system("cls");
		display_potion_shop();
		break;
	case 3:
		system("cls");
		break;
	}
}

int buy_item(Item* _item_to_buy, Inventory* _inventory) {
	int inventory_space = _inventory->get_inventory_size();
	//std::cout << "I" << inventory_space;
	//system("Pause");

	if (inventory_space < _inventory->get_max_inventory_space()) { //Only add items if there's room in the inventory
		_inventory->add_item(_item_to_buy);
		return 0;
	}
	else {
		return 1;
	}
}