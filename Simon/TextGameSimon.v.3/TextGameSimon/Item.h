#pragma once

#include "stdafx.h"
#include "Armor.h"

enum ItemType { WeaponItem, ArmorItem, PotionItem };

class Item
{
public:
	Item(std::string _name, int _cost, ItemType _type);

	std::string get_name() { return this->name; }
	int get_cost() { return this->cost; }
	ItemType get_type() { return this->type; }

	virtual ArmorType get_armor_type() { std::cout << "Not implemeted" << std::endl; return NoArmorType; }
	virtual double get_damage() { std::cout << "Not implemented" << std::endl; return 0; };
	virtual double get_crit_chance() { std::cout << "Not implemented" << std::endl; return 0; };
	virtual double get_accuracy() { std::cout << "Not implemented" << std::endl; return 0; };
	virtual double get_damage_reduction() { std::cout << "Not implemented" << std::endl; return 0; };
	virtual double get_deflect_chance() { std::cout << "Not implemented" << std::endl; return 0; };
	virtual double get_health_boost() { std::cout << "Not implemented" << std::endl; return 0; };
	virtual double get_effectiveness() { std::cout << "Not implemented" << std::endl; return 0; }
protected:
	std::string name;
	int cost;
	ItemType type;
};

