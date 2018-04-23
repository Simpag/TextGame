#include "stdafx.h"
#include "Equipment_Inventory.h"


Equipment_Inventory::Equipment_Inventory(int _space) : Inventory (equipment_inventory_space)
{
	equipment_inventory_space = _space;
}

void Equipment_Inventory::equip_item(Item* _item_to_equip, Inventory* _inventory) {
	inventory.push_back(_item_to_equip);
	_inventory->remove_item(_item_to_equip);
}