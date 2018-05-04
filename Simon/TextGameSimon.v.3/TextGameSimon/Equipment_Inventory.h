#pragma once

#include "Inventory.h"
#include <Array>

class Character; //Prototype character class. Crashes if I import character.h

class Equipment_Inventory
{
public:
	Equipment_Inventory();
	void equip_item(Item* _item_to_equip, Inventory* _inventory, Character* _player);

	//Getters
	std::string get_name(int _index) { return equipment_inventory[_index]->get_name(); }
	int get_equipment_inventory_size() { return this->equipment_inventory_size; }
	Item* get_item(int _index) { return this->equipment_inventory[_index]; }

	bool get_got_helmet() { return got_helmet; }
	bool get_got_chest() { return got_chest; }
	bool get_got_leg() { return got_leg; }
	bool get_got_feet() { return got_feet; }
	bool get_got_weapon() { return got_weapon; }
	bool get_got_potion() { return got_potion; }
private:
	void calculate_stats(Character* _player);

	bool got_helmet, got_chest, got_leg, got_feet, got_weapon, got_potion;

	int equipment_inventory_size;
	Item* equipment_inventory[6];
};

