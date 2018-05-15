#include "stdafx.h"
#include "Item.h"


Item::Item(std::string _name, int _cost, int _worth, ItemType _type) {
	this->name = _name;
	this->cost = _cost;
	this->worth = _worth;
	this->type = _type;
}
