#pragma once

#include "stdafx.h"

#include "Potion.h"

enum PotionName { Small, Medium, Large };

//Weapon name (string _name, int _cost, int _worth, ItemType _type, double _effectiveness)

std::vector<Potion*> potion_vector{
	new Potion("Small", 100, 80, PotionItem, 0.2),
	new Potion("Medium", 300, 250, PotionItem, 0.4),
	new Potion("Big", 600, 500, PotionItem, 0.6)
};