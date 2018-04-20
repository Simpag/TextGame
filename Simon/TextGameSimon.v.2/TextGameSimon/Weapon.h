#pragma once

#include "Item.h"

class Weapon : public Item
{
public:
	Weapon(std::string _name, int _cost, ItemType _type, int _damage, double _crit_chance, double _accuracy);

	int get_damage() { return this->damage; }
	double get_crit_chance() { return this->crit_chance; }
	double get_accuracy() { return this->accuracy; }
protected:
	int damage;
	double crit_chance;
	double accuracy;
};

