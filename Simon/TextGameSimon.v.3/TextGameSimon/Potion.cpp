#include "stdafx.h"
#include "Potion.h"


Potion::Potion(std::string _name, int _cost, ItemType _type, double _effectiveness) : Item (_name, _cost, _type) {
	this->effectiveness = _effectiveness;
}

void Potion::use_potion(Character* _character) {
	_character->add_health(_character->get_max_health() * this->effectiveness);
}