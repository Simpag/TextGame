#pragma once

#include "stdafx.h"

#include "Weapon.h"

enum WeaponName { WTest1, WTest2 };

//Weapon name (string _name, int _cost, int _worth, ItemType _type, int _damage, double _crit_chance, double _accuracy)

std::vector<Weapon*> weapon_vector {
	new Weapon("Wtest1", 20, 15, WeaponItem, 25, 0.5, 0.5),
	new Weapon("Wtest2", 25, 20, WeaponItem, 30, 0.2, 0.2)
};