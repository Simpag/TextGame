// TextGameSimon.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "TextGameSimon.h"

#include "Item.h"

using namespace std;

void display_main_menu(bool *running);
void display_arena_sub_menu();
void display_shop_sub_menu();
void display_inventory();
void save_and_quit(bool *runnnig);

int main()
{
	bool running = true;

	while (running) {
		display_main_menu(&running);
	}

	system("pause");
    return 0;
}

void display_main_menu(bool *running) {
	int _state;

	cout << "[0] Arena \n[1] Shop \n[2] Inventory \n[3] Save and quit \n";
	cin >> _state;

	switch (_state) {
	case 0:
		display_arena_sub_menu();
		break;
	case 1:
		display_shop_sub_menu();
		break;
	case 2:
		display_inventory();
		break;
	case 3: 
		save_and_quit(running);
		break;
	}
	system("cls");
}

void display_arena_sub_menu() {
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

void display_shop_sub_menu() {
	int _state;

	cout << "[0] Weapon \n[1] Armor \n[2] Potions \n[3] Back \n";
	cin >> _state;

	switch (_state) {
	case 0:
		
		break;
	case 1:
		
		break;
	case 2:
		
		break;
	case 3:
		system("cls");
		break;
	}
}

void display_inventory() {
	
}

void save_and_quit(bool *running) {
	*running = false;
}