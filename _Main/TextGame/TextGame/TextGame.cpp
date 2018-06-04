// TextGame.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
//#include "limits.h"
#include "time.h"
#include "Item.h"
#include "Inventory.h"
#include "Character.h"
#include "Enemy.h"

void display_arena_menu();	//Dun know why it's needed but it works
void save_and_quit(bool *runnnig);

//string _name, double _health, double _max_health, double _damage, double _damage_reduction, double _accuracy, double _deflect_chance, double _crit_chance
Character player("insert player name", 100, 100, 10, 0.1, 0.6, 0.2, 0.2);

#include "Menu_Main.h"

int main() {
	bool running = true;
	std::string name;

	/* initialize random seed: */
	srand(time(NULL));

	std::cout << "Name your firstborn child! \n";
	std::getline(std::cin, name);

	player.set_name(name);

	system("cls");

	while (running) {
		display_main_menu(&running);
	}

	return 0;
}

void save_and_quit(bool *running) {
	*running = false;
}