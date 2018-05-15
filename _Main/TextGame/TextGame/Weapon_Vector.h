#pragma once

#include "stdafx.h"

#include "Weapon.h"

enum WeaponName { Stick, PointyStick, WoodenDagger, WoodenSword, RustySword, SteelSword, CarbonFiberSword, 
	HighSchoolBadmintonTrophy, Slightlyusedtoothbrush, VapeSword, FrenchHotdog, SwordfishSword, Dorito, 
	Iphone5c, WilliamKarateKid, LucasWhatah, SimonHackerman, LucasHustledVodka, JoakimStol, BPD };

//Weapon name (string _name, int _cost, int _worth, ItemType _type, double _damage, double _crit_chance, double _accuracy)

std::vector<Weapon*> weapon_vector{
	new Weapon("Stick", 500, 300, WeaponItem, 4, 0.01, 0.01),
	new Weapon("Pointy Stick", 750, 540, WeaponItem, 10, 0.02, 0.015),
	new Weapon("Wooden Sword", 2500, 1200, WeaponItem, 22, 0.05, 0.05),
	new Weapon("Wooden Dagger", 6100, 2100, WeaponItem, 46, 0.02, 0.02),
	new Weapon("Rusty Sword", 12300, 7000, WeaponItem, 67, 0.03, 0.03),
	new Weapon("Steel Sword", 24000, 16000, WeaponItem, 100, 0.06, 0.06),
	new Weapon("Carbon Fiber Sword", 49999, 30000, WeaponItem, 250, 0.1, 0.15),
	new Weapon("2007 High school badminton trophy", 99998, 67000, WeaponItem, 600, 0.05, 0.211),
	new Weapon("Slightly used toothbrush", 188000, 120000, WeaponItem, 1000, 0.15, 0.2),
	new Weapon("Vape Sword", 300000, 212000, WeaponItem, 1700, 0.6, 0.5),
	new Weapon("French Hotdog", 999999, 631000, WeaponItem, 2999, 0.05, 0.2),
	new Weapon("Swordfish Sword", 1500000, 1120000, WeaponItem, 7000, 0.15, 0.19),
	new Weapon("Dorito", 3500000, 2800000, WeaponItem, 20000, 0.3, 0.25),
	new Weapon("Iphone 5c", 7770000, 5600000, WeaponItem, 80000, 0.4, 0.26),
	new Weapon("William Karate Kid", 25000000, 18000000, WeaponItem, 0, 0.4, 0.3),
	new Weapon("Lucas Whatah", 55000000, 39900000, WeaponItem, 0, 0.4, 0.3),
	new Weapon("Simon Hackerman", 155000000, 99999998, WeaponItem, 0, 0.4, 0.3),
	new Weapon("Lucas Hustled Vodka", 250000000, 188000000, WeaponItem, 0, 0.4, 0.3),
	new Weapon("Joakims Stol", 500000000, 5000000000, WeaponItem, 5, 0.4, 0.3),
	new Weapon("BPD", 9999999999999999, 9999999999999999, WeaponItem, 10000000, 1, 1), //Way too OP but it’s cool
};

