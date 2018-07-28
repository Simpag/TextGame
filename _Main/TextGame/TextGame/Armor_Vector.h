#pragma once

#include "stdafx.h"

#include "Armor.h"

enum ArmorName { Hood, LeatherCap, HardenedLeatherHat, RingmailCoif, LightMailHelmet, PlateHelmet, PlotArmorCoronet, 
	GimpsuitHeaddress, Rags, LeatherJacket, HardenedLeatherJacket, RingmailShirt, LightMailChestplate, PlateCarapace, 
	PlotArmorPlateRobe, GimpsuitUpperSpandex, RuggedPants, LeatherPants, HardenedLeatherTrousers, RingmailPantaloons, 
	LightMailLegguards, PlateLeggings, PlotArmorTrousers, GimpSuitLowerSpandex, Sacks, LeatherBoots, HardenedLeatherBoots, 
	RingmailSocks, LightMailGreaves, PlateSabatons, PlotArmorSlippers, GimpsuitFootsies };

//Armor(string _name, int _cost, int _worth, ItemType _item_type, ArmorType _armor_type, double _damage_reduction, double _accuracy, double _deflect_chance, double _health_boost)
class ArmorVector {
public:
	std::vector<Armor*> vector{
		//Helmets
		new Armor("Hood", 200, 200, ArmorItem, Helmet, 0.01, 0.01, 0, 250),
		new Armor("Leather Cap", 4000, 400, ArmorItem, Helmet, 0.05, 0.05, 0, 500),
		new Armor("Hardened Leather Hat", 10000, 6000, ArmorItem, Helmet, 0.015, 0.015, 0, 1000),
		new Armor("Ringmail Coif", 17000, 12000, ArmorItem, Helmet, 0.025, 0.025, 0.01, 2500),
		new Armor("Light Mail Helmet", 38000, 15000, ArmorItem, Helmet, 0.0375, 0.0375, 0.025, 10000),
		new Armor("Plate Helmet", 90000, 20000, ArmorItem, Helmet, 0.0425, 0.0425, 0.005, 87500),
		new Armor("Plot Armor Coronet", 180000, 35000, ArmorItem, Helmet, 0.005, 0.005, 001, 625000),
		new Armor("Gimpsuit Headdress", 9999999999999999, 9999999999999999, ArmorItem, Helmet, 0.175, 0.2, 0.15, 2500000), // Fucking OP

		//Chests
		new Armor("Rags", 500, 50, ArmorItem, Chest, 0.01, 0.001, 0, 250),
		new Armor("Leather Jacket", 6000, 4, ArmorItem, Chest, 0.05, 0.05, 0, 500),
		new Armor("Hardened Leather Jacket", 13000, 6, ArmorItem, Chest, 0.015, 0.015, 0, 1000),
		new Armor("Ringmail Shirt", 2000, 12000, ArmorItem, Chest, 0.025, 0.025, 0.01, 2500),
		new Armor("Light Mail Chestplate",44000 , 15000, ArmorItem, Chest, 0.0375, 0.0375, 0.25, 10000),
		new Armor("Plate Carapace", 150000, 20000, ArmorItem, Chest, 0.045, 0.045, 0.005, 87500),
		new Armor("Plot Armor Plate Robe", 300000, 35000, ArmorItem, Chest, 0.125, 0.125, 0.05, 625000),
		new Armor("Gimpsuit Upper Spandex", 9999999999999999, 9999999999999999, ArmorItem, Chest, 0.23, 0.3, 0.2, 2500000),

		//Leggings
		new Armor("Rugged Pants", 200, 200, ArmorItem, Leg, 0.005, 0.005, 0, 250),
		new Armor("Leather Pants", 4000, 4000, ArmorItem, Leg, 0.01, 0.01, 0, 500),
		new Armor("Hardened Leather Trousers", 10000, 6000, ArmorItem, Leg, 0.015, 0.01, 0, 1000),
		new Armor("Ringmail Pantaloons", 17000, 12000, ArmorItem, Leg, 0.025, 0.025, 0.015, 2500),
		new Armor("Light Mail Legguards", 38000, 15000, ArmorItem, Leg, 0.0375, 0.0375, 0.25, 10000),
		new Armor("Plate Leggings", 90000, 20000, ArmorItem, Leg, 0.0425, 0.425, 0.05, 87500),
		new Armor("Plot Armor Trousers", 180000, 35000, ArmorItem, Leg, 0.075, 0.1, 0.025, 625000),
		new Armor("Gimp Suit Lower Spandex", 9999999999999999, 9999999999999999, ArmorItem, Leg, 0.175, 0.2, 0.15, 2500000),

		//Feet
		new Armor("Sacks", 200, 200, ArmorItem, Feet, 0.005, 0.005, 0, 250),
		new Armor("Leather Boots", 40000, 4000, ArmorItem, Feet ,0.01, 0.01, 0, 500),
		new Armor("Hardened Leather Boots", 10000, 6000, ArmorItem, Feet, 0.015, 0.01, 0, 1000),
		new Armor("Ringmail Socks", 17000, 12000, ArmorItem, Feet, 0.025, 0.025, 0.015, 2500),
		new Armor("Light Mail Greaves", 38000, 15000, ArmorItem, Feet, 3.25, 3.25, 0.2, 10000),
		new Armor("Plate Sabatons", 90000, 20000, ArmorItem, Feet, 0.0375, 0.0375, 0.3, 87500),
		new Armor("Plot Armor Slippers", 180000, 35000, ArmorItem, Feet, 0.05, 0.055, 0.01, 625000),
		new Armor("Gimpsuit Footsies", 9999999999999999, 9999999999999999, ArmorItem, Feet, 0.12, 0.175, 0.1, 2500000)
	};
};

static ArmorVector armor_vector;