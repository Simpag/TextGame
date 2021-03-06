#pragma once
#include "stdafx.h"

void display_main_menu(bool *running) {
	int _input;

	cout << "[0] Arena \n[1] Shop \n[2] Inventory \n[3] Save and quit \n";
	cin >> _input;

	switch (_input) {
	case 0:
		system("cls");
		display_arena_menu();
		break;
	case 1:
		system("cls");
		display_shop_menu();
		break;
	case 2:
		system("cls");
		display_inventory(test.inventory, test.equipment_inventory);
		break;
	case 3:
		system("cls");
		save_and_quit(running);
		break;
	}
}