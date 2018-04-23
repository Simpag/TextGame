#pragma once

#include "stdafx.h"
#include "Equipment_Inventory.h"

class Character
{
public:
	Character();
	Inventory* inventory = new Inventory();
	Equipment_Inventory* equipment_inventory = new Equipment_Inventory;
private:
	int health;
};

