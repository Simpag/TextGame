#pragma once

#include "stdafx.h"

#include "Item_Functions.h"
#include "Weapon_Shop.h"
#include "Armor_Shop.h"
#include "Potion_Shop.h"
#include "Menu_Sell.h"

void display_shop_menu() {
	int _state;

	std::cout << "[0] Weapon \n[1] Armor \n[2] Potions \n[3] Sell \n[4] Back \n";
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
		display_sell(player.inventory, &player);
		break;
	case 4:
		system("cls");
		break;
	}
}