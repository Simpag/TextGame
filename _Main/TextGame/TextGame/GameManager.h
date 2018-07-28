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
	void load_player_stats_from_save_string(Player *_player);
	std::string convert_to_string();
	std::string extract_element(std::string *_save_string);

	bool save_file_exist;
	const std::string file_location = "C:/Users/simon/Desktop/TextGameSaveFile.txt";


//Vars
	//Character
	std::string name;
	double money;

	//Player
	int challenge_mode_level;

	//Inventory
	std::vector<std::string> inventory;
	int max_inventory_space;

	//Equipment Inventory
	std::vector<std::string> equipment_inventory;
};

