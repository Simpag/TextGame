// TextGameSimon.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "windows.h"
#include <iostream>
#include "TextGameSimon.h"

#include "Item.h"
#include "Shop.h"
#include "Weapon.h"

using namespace std;

void display_main_menu(bool *running);
void display_arena_menu();
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
		system("cls");
		display_arena_menu();
		break;
	case 1:
		system("cls");
		display_shop_menu();
		break;
	case 2:
		system("cls");
		display_inventory();
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

void display_inventory() {
	
}

void save_and_quit(bool *running) {
	*running = false;
}