#pragma once

#include "stdafx.h"
#include "Equipment_Inventory.h"

class Character
{
public:
	//Public vars
	Inventory* inventory = new Inventory();
	Equipment_Inventory* equipment_inventory = new Equipment_Inventory();

	Character(std::string _name, double _health);

	//Fighting
	void perform_attack(Character* _opponent, int _type);

	//Misc
	void remove_money(int _amount) { this->money -= _amount; }
	void add_health(double _amount);

	//Getters
	double get_health() { return this->health; }
	double get_max_health() { return this->max_health; }
	std::string get_name() { return this->name; }

	//Setters
	void set_damage(double _damage) { this->damage = _damage; }
	void set_max_health(double _max_health) { this->max_health = _max_health; this->health = this->max_health; }
	void set_damage_reduction(double _damage_reduction) { this->damage_reduction = _damage_reduction; }
	void set_accuracy(double _accuracy) { this->accuracy = _accuracy; }
	void set_deflect_chance(double _defelct_chance) { this->deflect_chance = _defelct_chance; }
	void set_crit_chance(double _crit_chance) { this->crit_chance = _crit_chance; }
protected:
	int money;
	double health;
	double damage;
	double max_health;
	double damage_reduction;
	double accuracy;
	double deflect_chance;
	double crit_chance;
	std::string name;

	void deal_damage(Character* _opponent, double _damage);
	void take_damage(Character* _opponent, double _damage);
};

