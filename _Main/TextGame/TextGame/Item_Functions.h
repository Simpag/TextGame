#pragma once

#include "stdafx.h"
#include "Item.h"

int buy_item(Item* _item_to_buy, Inventory* _inventory, Character* _player) {
	int inventory_space = _inventory->get_inventory_size();

	if (inventory_space < _inventory->get_max_inventory_space() && _player->get_money() >= _item_to_buy->get_cost()) { //Only add items if there's room in the inventory and the player got enough money
		_inventory->add_item(_item_to_buy);
		_player->remove_money(_item_to_buy->get_cost());
		return 0;
	}
	else if (!(inventory_space < _inventory->get_max_inventory_space())) {
		return 1;	//Couldn't buy item, inventory's full
	}
	else if (!(_player->get_money() >= _item_to_buy->get_cost())) {
		return 2; //Couldn't buy item, not enough money
	}
}

void sell_item(Item* _item_to_sell, Inventory* _inventory, Character* _player) {
	_inventory->remove_item(_item_to_sell);
	_player->add_money(_item_to_sell->get_worth());
}