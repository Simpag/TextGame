#pragma once
#include "stdafx.h"

#include "Menu_Arena.h"
#include "Menu_Inventory.h"
#include "Menu_Stats.h"
#include "Menu_Shop.h"

void display_main_menu(bool *running) {
	int _input;

	cout << "[0] Arena \n[1] Shop \n[2] Inventory \n[3] Stats \n[4] Save and quit \n";
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
		display_stats(&test);
		break;
	case 4:
		system("cls");
		save_and_quit(running);
		break;
	}
}