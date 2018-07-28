#include "stdafx.h"
#include <fstream>
#include "GameManager.h"

/*#include "Armor_Vector.h"
#include "Weapon_Vector.h"
#include "Potion_Vector.h"*/

GameManager::GameManager() {
	std::fstream file;
	file.open("TextGameSaveFile.txt", std::ios_base::out | std::ios_base::in);  // will not create file
	if (file.is_open())
	{
		//File exists
		save_file_exist = true;
	}
	else
	{
		save_file_exist = false;
	}
}

int GameManager::save_game(Player *_player) {
	/*
Character
	name
	money

Player
	challenge mode level

Inventory
	max inventory space
	inventory size
	inventory vector

Equipment Inventory
	max inventory space
	inventory space
	equipment inventory array
	*/

	//Character
	this->name = _player->get_name();
	this->money = _player->get_money();

	//Player
	this->challenge_mode_level = _player->get_challenge_mode_level();

	//Inventory
	max_inventory_space = _player->inventory->get_max_inventory_space();
	for (int i = 0; i < _player->inventory->get_inventory_size(); i++)
	{
		inventory.push_back(_player->inventory->get_item(i)->get_name());
	}


	//Single string output
	std::string save_string = convert_to_string();

	//Write file to harddrive
	std::ofstream save_file(this->file_location);
	if (save_file.is_open()) {
		save_file << save_string;
	}

	std::cout << save_string;
	save_file.close();
	return 0;
}

std::string GameManager::convert_to_string() {
	std::string _string;

	_string += this->name + "|";
	_string += std::to_string(this->money) + "|";
	_string += std::to_string(this->challenge_mode_level) + "|";
	_string += std::to_string(this->max_inventory_space) + "|";
	_string += std::to_string(inventory.size()) + "|"; //write inventory size
	for (int i = 0; i < this->inventory.size(); i++) //Saving inventory
	{
		_string += this->inventory.at(i) + "|";
	}
	

	return _string;
}

void GameManager::load_game(Player *_player) {
	//Read save file
	std::string line, save_string;
	std::ifstream save_file(this->file_location);
	if (save_file.is_open()) {
		while (getline(save_file, line)) {
			save_string += line;
		}
	}
	save_file.close();

	std::cout << save_string << std::endl;

	bool _loading_elements = true;
	int _elements = 0;

	while (_loading_elements) {
		if (!save_string.empty()) {
			std::string _element;

			_element = extract_element(&save_string);
			_elements++;

			switch (_elements) {
			case 1:
				this->name = _element;
				break;
			case 2:
				this->money = std::stod(_element);
				break;
			case 3:
				this->challenge_mode_level = stoi(_element);
				break;
			case 4:
				this->max_inventory_space = stoi(_element);
				break;
			case 5: //Loading inventory
				int _size = stoi(_element);
				for (int i = 0; i < _size; i++)
				{
					_element = extract_element(&save_string);
					inventory.push_back(_element);
					_elements++;
				}
			}
		}
		else { //If the file is empty
			_loading_elements = false;
		}
	}

	system("Pause");
	load_player_stats(_player);
}

std::string GameManager::extract_element(std::string *_save_string) {
	std::string _element;
	while (_save_string->at(0) != '|') {
		_element += _save_string->at(0);
		_save_string->erase(0, 1);
	}
	_save_string->erase(0, 1); //Remove last "|" symbol

	std::cout << "Extracted: " << _element << " \n";

	return _element;
}

void GameManager::load_player_stats(Player *_player) {
	//Character
	_player->set_name(this->name);
	_player->add_money(this->money);
	
	//Player
	_player->set_challenge_mode_level(this->challenge_mode_level);
	
	//Inventory
	_player->inventory->set_max_inventory_space(this->max_inventory_space);
	/*
	for (int i = 0; i < inventory.size(); i++) {
		//Armor Items
		for (int j = 0; j < armor_vector.size(); j++) {
			if (inventory.at(i) == armor_vector.at(j)->get_name()) {
				_player->inventory->add_item(armor_vector.at(j));
				break;
			}
		}

		//Weapon Items
		for (int j = 0; j < weapon_vector.size(); j++) {
			if (inventory.at(i) == weapon_vector.at(j)->get_name()) {
				_player->inventory->add_item(weapon_vector.at(j));
				break;
			}
		}

		//Potion Items
		for (int j = 0; j < potion_vector.size(); j++) {
			if (inventory.at(i) == potion_vector.at(j)->get_name()) {
				_player->inventory->add_item(potion_vector.at(j));
				break;
			}
		}
	}*/
}
