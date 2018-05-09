#pragma once

#include "stdafx.h"

#include "Armor.h"

enum ArmorName { ATest1, ATest2 };

//Armor(string _name, int _cost, int _worth, ItemType _type, ArmorType, double _damage_reduction, double _accuracy, double _deflect_chance, double _health_boost)

std::vector<Item*> armor_vector{
	new Armor("Atest1", 12, 8, ArmorItem, Helmet, 0.2, 0.5, 0.5, 0.2),
	new Armor("Atest2", 19, 15, ArmorItem, Helmet, 0.5, 0.2, 0.2, 0.2)
};