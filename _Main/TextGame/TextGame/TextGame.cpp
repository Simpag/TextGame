// TextGame.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "time.h"

//Classes
#include "GameManager.h"
#include "Item.h"
#include "Inventory.h"
#include "Character.h"
#include "Player.h"
#include "Enemy.h"

void display_arena_menu();	//Dun know why it's needed but it works
void save_and_quit(bool *runnnig);

GameManager gamemanager;

//string _name, double _health, double _max_health, double _damage, double _damage_reduction, double _accuracy, double _deflect_chance, double _crit_chance
Player player("insert player name", 100, 100, 10, 0.1, 0.6, 0.2, 0.2);

#include "Menu_Main.h"

int main() {
	bool running = true;
	int load_save;
	std::string name;

	/* initialize random seed: */
	srand(time(NULL));

	if (gamemanager.save_file_exsists()) {
		std::cout << "Do you want to load save file? \n";
		std::cin >> load_save;

		if (load_save == 0) {
			gamemanager.load_game(&player);
		}
		else {
			std::cout << "Name your firstborn child! \n";
			std::getline(std::cin, name);

			player.set_name(name);
		}
	}
	else {
		std::cout << "No save file exists! \n";
		std::cout << "Name your firstborn child! \n";
		std::getline(std::cin, name);

		player.set_name(name);
	}

	

	system("cls");

	while (running) {
		display_main_menu(&running);
	}

	return 0;
}

void save_and_quit(bool *running) {
	gamemanager.save_game(&player);

	system("Pause");
	*running = false;
}