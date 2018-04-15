#include "stdafx.h"
#include "Item.h"


Item::Item(std::string _name, int _cost, ItemType _type) {
	this->name = _name;
	this->cost = _cost;
	this->type = _type;
}
