#pragma once

#include "Item.h"

class Weapon : public Item
{
public:
	Weapon(std::string _name, int _cost, ItemType _type, double _damage, double _crit_chance, double _accuracy);

	double get_damage() { return this->damage; }
	double get_crit_chance() { return this->crit_chance; }
	double get_accuracy() { return this->accuracy; }
protected:
	double damage;
	double crit_chance;
	double accuracy;
};

