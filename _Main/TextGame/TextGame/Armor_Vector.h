#pragma once

#include "stdafx.h"

#include "Armor.h"

enum ArmorName { Hood, LeatherCap, HardenedLeatherHat, RingmailCoif, LightMailHelmet, PlateHelmet, PlotArmorCoronet, 
	GimpsuitHeaddress, Rags, LeatherJacket, HardenedLeatherJacket, RingmailShirt, LightMailChestplate, PlateCarapace, 
	PlotArmorPlateRobe, GimpsuitUpperSpandex, RuggedPants, LeatherPants, HardenedLeatherTrousers, RingmailPantaloons, 
	LightMailLegguards, PlateLeggings, PlotArmorTrousers, GimpSuitLowerSpandex, Sacks, LeatherBoots, HardenedLeatherBoots, 
	RingmailSocks, LightMailGreaves, PlateSabatons, PlotArmorSlippers, GimpsuitFootsies };

//Armor(string _name, int _cost, int _worth, ItemType _item_type, ArmorType _armor_type, double _damage_reduction, double _accuracy, double _deflect_chance, double _health_boost)

std::vector<Armor*> armor_vector{
	//Helmets
	new Armor("Hood", 5, 2, ArmorItem, Helmet, 0.005, 0.005, 0, 0),
	new Armor("Leather Cap", 10, 4, ArmorItem, Helmet, 0.01, 0.01, 0, 0),
	new Armor("Hardened Leather Hat", 17, 6, ArmorItem, Helmet, 0.015, 0.015, 0, 0),
	new Armor("Ringmail Coif", 30, 12, ArmorItem, Helmet, 0.025, 0.025, 0.01, 0),
	new Armor("Light Mail Helmet", 43, 15, ArmorItem, Helmet, 0.0375, 0.0375, 0.025, 0),
	new Armor("Plate Helmet", 75, 20, ArmorItem, Helmet, 0.0425, 0.0425, 0.005, 0.1),
	new Armor("Plot Armor Coronet", 103, 35, ArmorItem, Helmet, 0.005, 0.005, 001, 0.12),
	new Armor("Gimpsuit Headdress", 10000000, 10000, ArmorItem, Helmet, 0.175, 0.2, 0.15, 0.2), // Fucking OP

	//Chests
	new Armor("Rags", 5, 2, ArmorItem, Chest, 0.005, 0.005, 0, 0),
	new Armor("Leather Jacket", 10, 4, ArmorItem, Chest, 0.01, 0.01, 0, 0),
	new Armor("Hardened Leather Jacket", 17, 6, ArmorItem, Chest, 0.015, 0.015, 0, 0),
	new Armor("Ringmail Shirt", 30, 12, ArmorItem, Chest, 0.025, 0.025, 0.01, 0),
	new Armor("Light Mail Chestplate", 43, 15, ArmorItem, Chest, 0.0375, 0.0375, 0.25, 0),
	new Armor("Plate Carapace", 75, 20, ArmorItem, Chest, 0.045, 0.045, 0.005, 0.1),
	new Armor("Plot Armor Plate Robe", 103, 35, ArmorItem, Chest, 0.125, 0.125, 0.05, 0.12),
	new Armor("Gimpsuit Upper Spandex", 10000000, 10000, ArmorItem, Chest, 0.23, 0.3, 0.2, 0.2),

	//Leggings
	new Armor("Rugged Pants", 5, 2, ArmorItem, Leg, 0.005, 0.005, 0, 0),
	new Armor("Leather Pants", 10, 4, ArmorItem, Leg, 0.01, 0.01, 0, 0),
	new Armor("Hardened Leather Trousers", 17, 6, ArmorItem, Leg, 0.015, 0.01, 0, 0),
	new Armor("Ringmail Pantaloons", 30, 12, ArmorItem, Leg, 0.025, 0.025, 0.015, 0),
	new Armor("Light Mail Legguards", 43, 15, ArmorItem, Leg, 0.0375, 0.0375, 0.25, 0),
	new Armor("Plate Leggings", 75, 20, ArmorItem, Leg, 0.0425, 0.425, 0.05, 0.1),
	new Armor("Plot Armor Trousers", 103, 35, ArmorItem, Leg, 0.075, 0.1, 0.025, 0.12),
	new Armor("Gimp Suit Lower Spandex", 10000000, 10000, ArmorItem, Leg, 0.175, 0.2, 0.15, 0.2),

	//Feet
	new Armor("Sacks", 5, 2, ArmorItem, Feet, 0.005, 0.005, 0, 0),
	new Armor("Leather Boots", 10, 4, ArmorItem, Feet ,0.01, 0.01, 0, 0),
	new Armor("Hardened Leather Boots", 17, 6, ArmorItem, Feet, 0.015, 0.01, 0, 0),
	new Armor("Ringmail Socks", 30, 12, ArmorItem, Feet, 0.025, 0.025, 0.015, 0),
	new Armor("Light Mail Greaves", 43, 15, ArmorItem, Feet, 3.25, 3.25, 0.2, 0),
	new Armor("Plate Sabatons", 75, 20, ArmorItem, Feet, 0.0375, 0.0375, 0.3, 0.1),
	new Armor("Plot Armor Slippers", 103, 35, ArmorItem, Feet, 0.05, 0.055, 0.01, 0.12),
	new Armor("Gimpsuit Footsies", 10000000, 10000, ArmorItem, Feet, 0.12, 0.175, 0.1, 0.2)
};


