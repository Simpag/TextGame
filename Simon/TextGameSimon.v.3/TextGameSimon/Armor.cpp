#include "stdafx.h"
#include "Armor.h"


Armor::Armor(std::string _name, int _cost, ItemType _item_type, ArmorType _armor_type, double _damage_reduction, double _accuracy, double _deflect_chance, double _health_boost) : Item(_name, _cost, _item_type) {
	this->armor_type = _armor_type;
	this->damage_reduction = _damage_reduction;
	this->accuracy = _accuracy;
	this->deflect_chance = _deflect_chance;
	this->health_boost = _health_boost;
}