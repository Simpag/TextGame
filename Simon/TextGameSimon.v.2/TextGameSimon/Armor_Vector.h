#pragma once

#include "stdafx.h"
#include "windows.h"
#include "iostream"
#include "vector"
#include "string"

#include "Armor.h"

enum ArmorName { ATest1, ATest2} ;

//Armor(string _name, int _cost, ItemType _type, double _damage_reduction, double _accuracy, double _deflect_chance)

std::vector<Armor*> armor_vector{
	new Armor("Atest1", 12, ArmorItem, 0.2, 0.5, 0.5),
	new Armor("Atest2", 19, ArmorItem, 0.5, 0.2, 0.2)
};