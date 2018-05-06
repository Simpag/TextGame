#pragma once
#include "Item.h"
#include "Character.h"

class Potion :
	public Item
{
public:
	Potion(std::string _name, int _cost, int _worth, ItemType _type, double _effectiveness);

	void use_potion(Character* _character);

	double get_effectiveness() { return this->effectiveness; };
private:
	double effectiveness;
};

