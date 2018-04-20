#pragma once

#include "iostream"

enum ItemType { WeaponItem, ArmorItem, PotionItem };

class Item
{
public:
	Item(std::string _name, int _cost, ItemType _type);

	std::string get_name() { return this->name; }
	int get_cost() { return this->cost; }
	ItemType get_type() { return this->type; }

protected:
	std::string name;
	int cost;
	ItemType type;
};

