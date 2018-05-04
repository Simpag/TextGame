#pragma once

#include "stdafx.h"

#include "Potion.h"

enum PotionName { Small, Medium, Large };

//Weapon name (string _name, int _cost, ItemType _type, double _effectiveness)

std::vector<Potion*> potion_vector{
	new Potion("Small", 100, PotionItem, 0.2),
	new Potion("Medium", 300, PotionItem, 0.4),
	new Potion("Big", 600, PotionItem, 0.6)
};