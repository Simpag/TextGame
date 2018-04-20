#pragma once

#include "Item.h"

int buy_item(Item* _item_to_buy) {
	int inventory_space = inventory.size();
	std::cout << "I" << inventory_space;
	system("Pause");

	if (inventory_space < max_inventory_space) {
		inventory.push_back(_item_to_buy);
		return 0;
	}
	else {
		return 1;
	}
}