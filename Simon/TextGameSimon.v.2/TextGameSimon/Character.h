#pragma once

#include "stdafx.h"
#include "Equipment_Inventory.h"

class Character
{
public:
	//Public vars
	Inventory* inventory = new Inventory();
	Equipment_Inventory* equipment_inventory = new Equipment_Inventory;

	Character(std::string _name, double _health);

	//Fighting
	void perform_attack(Character* _opponent, int _type);

	//Getters
	double get_health() { return this->health; }
	double get_max_health() { return this->max_health; }
	std::string get_name() { return this->name; }

	//Setters
	void set_health(double _health) { this->health = _health; }

protected:
	double health;
	double damage;
	double max_health;
	double damage_reduction;
	double accuracy;
	double defelct_chance;
	double crit_chance;
	std::string name;

	void deal_damage(Character* _opponent, double _damage);
	void take_damage(Character* _opponent, double _damage);
};

