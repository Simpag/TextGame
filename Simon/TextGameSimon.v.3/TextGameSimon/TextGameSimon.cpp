// TextGameSimon.cpp : Defines the entry point for the console application.
//

#include "TextGameSimon.h"

#include "stdafx.h"
#include "time.h"
#include "Item.h"
#include "Inventory.h"
#include "Character.h"
#include "Enemy.h"

using namespace std;

void display_main_menu(bool *running);
void display_arena_menu();
void save_and_quit(bool *runnnig);

Character test("Hero", 100);

#include "Menu_Main.h"

int main() {
	bool running = true;
	string name;

	test.add_money(1500);

	/* initialize random seed: */
	srand(time(NULL));

	while (running) {
		display_main_menu(&running);
	}

	return 0;
}

void save_and_quit(bool *running) {
	*running = false;
}