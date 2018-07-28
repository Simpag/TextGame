#pragma once
#include "Player.h"

class GameManager
{
public:
	GameManager();

	bool save_file_exsists() { return true; }

	int save_game(Player *_player);
	void load_game(Player *_player);

private:
	void load_player_stats(Player *_player);
	bool save_file_exist;
	std::string file_location = "C:/Users/simon/Desktop/TextGameSaveFile.txt";

	std::string convert_to_string();
	std::string extract_element(std::string *_save_string);

//Vars
	//Character
	std::string name;
	double money;

	//Player
	int challenge_mode_level;

	//Inventory
	std::vector<std::string> inventory;
	int max_inventory_space;
};

