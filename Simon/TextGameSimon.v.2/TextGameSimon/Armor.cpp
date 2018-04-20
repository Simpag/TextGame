#include "stdafx.h"
#include "Armor.h"


Armor::Armor(std::string _name, int _cost, ItemType _type, double _damage_reduction, double _accuracy, double _deflect_chance) : Item(_name, _cost, _type) {
	this->damage_reduction = _damage_reduction;
	this->accuracy = _accuracy;
	this->defelct_chance = _deflect_chance;
}