#include "stdafx.h"
#include <fstream>
#include "GameManager.h"

#include "Armor_Vector.h"
#include "Weapon_Vector.h"
#include "Potion_Vector.h"

GameManager::GameManager() {
	std::fstream file;
	file.open(file_location, std::ios_base::out | std::ios_base::in);  // will not create file
	if (file.is_open())
	{
		//File exists
		save_file_exist = true;
	}
	else
	{
		save_file_exist = false;
	}
	file.close();

	//Reset variables
	name.clear();
	money = 0;
	challenge_mode_level = 0;
	max_inventory_space = 0;
	inventory.clear();
	equipment_inventory.clear();
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

	//Equipment Inventory
	//Helmet
	if (_player->equipment_inventory->get_got_helmet())
		equipment_inventory.push_back(_player->equipment_inventory->get_item(0)->get_name());
	//Chest
	if (_player->equipment_inventory->get_got_chest())
		equipment_inventory.push_back(_player->equipment_inventory->get_item(1)->get_name());
	//Leggings
	if (_player->equipment_inventory->get_got_leg())
		equipment_inventory.push_back(_player->equipment_inventory->get_item(2)->get_name());
	//Boots
	if (_player->equipment_inventory->get_got_feet())
		equipment_inventory.push_back(_player->equipment_inventory->get_item(3)->get_name());
	//Weapon
	if (_player->equipment_inventory->get_got_weapon())
		equipment_inventory.push_back(_player->equipment_inventory->get_item(4)->get_name());
	//Potion
	if (_player->equipment_inventory->get_got_potion())
		equipment_inventory.push_back(_player->equipment_inventory->get_item(5)->get_name());


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

	_string += std::to_string(equipment_inventory.size()) + "|"; //write inventory size
	for (int i = 0; i < this->equipment_inventory.size(); i++) //Saving inventory
	{
		_string += this->equipment_inventory.at(i) + "|";
	}
	
	std::cout << "Save: " << _string << std::endl;
	system("pause");
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

	std::cout << "Loading: " << save_string << std::endl;

	bool _loading_elements = true;
	int _elements = 0, _size;

	//Load variables from string
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
				_size = stoi(_element);
				for (int i = 0; i < _size; i++)
				{
					_element = extract_element(&save_string);
					inventory.push_back(_element);
					_elements++;
				}
				break;
			default://Loading equipment inventory
				_size = stoi(_element);
				for (int i = 0; i < _size; i++) {
					_element = extract_element(&save_string);
					equipment_inventory.push_back(_element);
					_elements++;
				}
			}
		}
		else { //If the file is empty
			_loading_elements = false;
		}
	}

	system("Pause");
	load_player_stats_from_save_string(_player);
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

void GameManager::load_player_stats_from_save_string(Player *_player) {
	//Character
	_player->set_name(this->name);
	_player->add_money(this->money);
	
	//Player
	_player->set_challenge_mode_level(this->challenge_mode_level);

	//Inventory
	_player->inventory->set_max_inventory_space(this->max_inventory_space);
	for (int i = 0; i < inventory.size(); i++) {
		//Armor Items
		for (int j = 0; j < armor_vector.vector.size(); j++) {
			if (inventory.at(i).compare(armor_vector.vector.at(j)->get_name()) == 0) {
				_player->inventory->add_item(armor_vector.vector.at(j));
				break;
			}
		}

		//Weapon Items
		for (int j = 0; j < weapon_vector.vector.size(); j++) {
			if (inventory.at(i).compare(weapon_vector.vector.at(j)->get_name()) == 0) {
				_player->inventory->add_item(weapon_vector.vector.at(j));
				break;
			}
		}

		//Potion Items
		for (int j = 0; j < potion_vector.vector.size(); j++) {
			if (inventory.at(i).compare(potion_vector.vector.at(j)->get_name()) == 0) {
				_player->inventory->add_item(potion_vector.vector.at(j));
				break;
			}
		}
	}

	//Equipment Inventory
	for (int i = 0; i < equipment_inventory.size(); i++) {
		//Armor Items
		for (int j = 0; j < armor_vector.vector.size(); j++) {
			if (equipment_inventory.at(i).compare(armor_vector.vector.at(j)->get_name()) == 0) {
				_player->equipment_inventory->force_equip_item(armor_vector.vector.at(j), _player);
				break;
			}
		}

		//Weapon Items
		for (int k = 0; k < weapon_vector.vector.size(); k++) {
			if (equipment_inventory.at(i).compare(weapon_vector.vector.at(k)->get_name()) == 0) {
				_player->equipment_inventory->force_equip_item(weapon_vector.vector.at(k), _player);
				break;
			}
		}

		//Potion Items
		for (int j = 0; j < potion_vector.vector.size(); j++) {
			if (equipment_inventory.at(i).compare(potion_vector.vector.at(j)->get_name()) == 0) {
				_player->equipment_inventory->force_equip_item(potion_vector.vector.at(j), _player);
				break;
			}
		}
	}
}
