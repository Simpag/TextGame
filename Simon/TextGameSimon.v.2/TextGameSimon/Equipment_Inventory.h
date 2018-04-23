#pragma once

#include "Inventory.h"

class Equipment_Inventory : public Inventory
{
public:
	Equipment_Inventory(int _space = 5);

	void equip_item(Item* _item_to_equip, Inventory* _inventory);
private:
	int equipment_inventory_space;
};

