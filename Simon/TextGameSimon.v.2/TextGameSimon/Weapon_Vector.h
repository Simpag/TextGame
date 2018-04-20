#pragma once

#include "stdafx.h"
#include "windows.h"
#include "iostream"
#include "vector"
#include "string"

#include "Weapon.h"

//Weapon name (string _name, int _cost, ItemType _type, int _damage, double _crit_chance, double _accuracy)

std::vector<Weapon*> weapon_vector {
	new Weapon("Wtest1", 20, WeaponItem, 25, 0.5, 0.5),
	new Weapon("Wtest2", 25, WeaponItem, 30, 0.2, 0.2)
};