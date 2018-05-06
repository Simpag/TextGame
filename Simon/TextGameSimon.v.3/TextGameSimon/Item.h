#pragma once

#include "stdafx.h"

enum ItemType { WeaponItem, ArmorItem, PotionItem, NoItem };
enum ArmorType { Helmet, Chest, Leg, Feet, NoArmorType };

class Item
{
public:
	Item(std::string _name, int _cost, int _worth, ItemType _type);

	std::string get_name() { return this->name; }
	int get_cost() { return this->cost; }
	int get_worth() { return this->worth; }
	ItemType get_type() { return this->type; }

	virtual double get_damage() { std::cout << "Not implemented" << std::endl; return 0; }
	virtual double get_crit_chance() { std::cout << "Not implemented" << std::endl; return 0; }
	virtual double get_accuracy() { std::cout << "Not implemented" << std::endl; return 0; }
	virtual double get_damage_reduction() { std::cout << "Not implemented" << std::endl; return 0; }
	virtual double get_deflect_chance() { std::cout << "Not implemented" << std::endl; return 0; }
	virtual double get_health_boost() { std::cout << "Not implemented" << std::endl; return 0; }
	virtual double get_effectiveness() { std::cout << "Not implemented" << std::endl; return 0; }
	virtual ArmorType get_armor_type() { std::cout << "Not implemented" << std::endl; return NoArmorType; }
protected:
	std::string name;
	int cost;
	int worth;
	ItemType type;
};

