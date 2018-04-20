#pragma once

#include "Item.h"

class Armor : public Item
{
public:
	Armor(std::string _name, int _cost, ItemType _type, double _damage_reduction, double _accuracy, double _deflect_chance);
protected:
	double damage_reduction;
	double accuracy;
	double defelct_chance;
};

