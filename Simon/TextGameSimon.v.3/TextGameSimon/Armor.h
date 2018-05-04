#pragma once

#include "Item.h"

class Armor : public Item
{
public:
	Armor(std::string _name, int _cost, ItemType _item_type, ArmorType _armor_type, double _damage_reduction, double _accuracy, double _deflect_chance, double _health_boost);

	double get_damage_reduction() { return this->damage_reduction; }
	double get_deflect_chance() { return this->deflect_chance; }
	double get_accuracy() { return this->accuracy; }
	double get_health_boost() { return this->health_boost; }
	ArmorType get_armor_type() { return this->armor_type; }
protected:
	ArmorType armor_type;
	double damage_reduction;
	double accuracy;
	double deflect_chance;
	double health_boost;
};

