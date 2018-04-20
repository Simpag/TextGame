#pragma once

#include "stdafx.h"
#include <iostream>

#include "Weapon_Shop.h"
#include "Armor_Shop.h"
#include "Potion_Shop.h"

#include "Weapon_Vector.h"


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