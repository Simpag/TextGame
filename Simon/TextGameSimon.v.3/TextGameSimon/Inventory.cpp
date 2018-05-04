#include "stdafx.h"
#include "Inventory.h"

Inventory::Inventory(int _max) {
	max_inventory_space = _max;
}

void Inventory::add_item(Item* _item_to_add) {
	inventory.push_back(_item_to_add);
}

void Inventory::remove_item(Item* _item_to_remove) {
	for (int i = 0; i < inventory.size(); i++) {
		if (inventory[i] == _item_to_remove) {
			inventory.erase(inventory.begin()+i);
			return;
		}
	}
}