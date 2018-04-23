// TextGameSimon.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "TextGameSimon.h"

#include "Item.h"
#include "Inventory.h"
#include "Display_Inventory.h"
#include "Character.h"
#include "Enemy.h"

using namespace std;

void display_main_menu(bool *running);
void display_arena_menu();
void save_and_quit(bool *runnnig);

Character test;

int main() {
	bool running = true;

	while (running) {
		display_main_menu(&running);
	}

	return 0;
}

#include "Shop.h"

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

void display_arena_menu() {
	int _state;

	cout << "[0] Challenge \n[1] Training \n[2] Back \n";
	cin >> _state;

	switch (_state) {
	case 0:

		break;
	case 1:

		break;
	case 2:
		system("cls");
		break;
	}
}

void save_and_quit(bool *running) {
	*running = false;
}