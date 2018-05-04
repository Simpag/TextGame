#pragma once
#include "Item.h"

class Inventory
{
public:
	Inventory(int _max = 10);

	void add_item(Item* _item_to_add);
	void remove_item(Item* _item_to_remove);
	Item* get_item(int _index) { return inventory.at(_index); }

	int get_max_inventory_space() { return this->max_inventory_space;  }
	void set_max_inventory_space(int _max) { this->max_inventory_space = _max;  }
	int get_inventory_size() { return inventory.size(); }
	std::string get_name(int _index) { return inventory.at(_index)->get_name(); }
protected:
	std::vector<Item*> inventory;
	int max_inventory_space;
};