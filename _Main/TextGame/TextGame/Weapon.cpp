#include "stdafx.h"
#include "Weapon.h"

Weapon::Weapon(std::string _name, int _cost, int _worth, ItemType _type, double _damage, double _crit_chance, double _accuracy) : Item( _name, _cost, _worth, _type) {
	this->damage = _damage;
	this->crit_chance = _crit_chance;
	this->accuracy = _accuracy;
}