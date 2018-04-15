#pragma once

#include "iostream"

enum ItemType { Weapon, Armor, Potion };

class Item
{
public:
	Item(std::string _name, int _cost, ItemType _type);

	std::string get_name() { return this->name; }
	int get_cost() { return this->cost; }
	ItemType get_type() { return this->type; }

private:
	std::string name;
	int cost;
	ItemType type;
};

