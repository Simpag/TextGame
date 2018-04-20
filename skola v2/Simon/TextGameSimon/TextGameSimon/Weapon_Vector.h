#pragma once

#include "stdafx.h"
#include "windows.h"
#include "iostream"
#include "vector"
#include "string"

#include "Item.h"
#include "Weapon.h"

std::vector<Weapon*> Weapon_Vector {
	//Weapon name (string _name, int _cost, ItemType _type, int _damage, double _crit_chance, double _accuracy)
	new Weapon("test1", 20, WeaponItem, 25, 0.5, 0.5)

	//Weapon test2("test2", 25, WeaponItem, 30, 0.2, 0.2)
}