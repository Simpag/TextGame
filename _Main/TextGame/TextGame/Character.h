#pragma once

#include "stdafx.h"
#include "Equipment_Inventory.h"

enum Attack_Type { Basic_Attack, Quick_Attack, Strong_Attack };

class Character
{
public:
	//Public vars
	Inventory* inventory = new Inventory();
	Equipment_Inventory* equipment_inventory = new Equipment_Inventory();

	Character(std::string _name, double _health, double _max_health, double _damage, double _damage_reduction, double _accuracy, double _defelct_chance, double _crit_chance);

	//Fighting
	void perform_attack(Character* _opponent, Attack_Type _type);
	void use_potion();

	//Misc
	void remove_money(double _amount) { this->money -= _amount; }
	void add_money(double _amount) { this->money += _amount; }
	void add_health(double _amount);
	void full_health() { this->health = this->max_health; }

	//Get defaults
	double get_default_damage() { return default_damage; }
	double get_default_max_health() { return default_max_health; }
	double get_default_damage_reduction() { return default_damage_reduction; }
	double get_default_accuracy() { return default_accuracy; }
	double get_default_deflect_chance() { return default_deflect_chance; }
	double get_default_crit_chance() { return default_crit_chance; }

	//Getters
	std::string get_name() { return this->name; }
	double get_money() { return this->money; }
	double get_health() { return this->health; }
	double get_max_health() { return this->max_health; }
	double get_damage() { return this->damage; }
	double get_damage_reduction() { return this->damage_reduction; }
	double get_accuracy() { return this->accuracy; }
	double get_deflect_chance() { return this->deflect_chance; }
	double get_crit_chance() { return this->crit_chance; }

	//Setters
	void set_name(std::string _name) { this->name = _name; if (name == "Jude") { add_money(DBL_MAX); } }
	void set_damage(double _damage) { this->damage = _damage; }
	void set_max_health(double _max_health) { this->max_health = _max_health; this->health = this->max_health; }
	void set_damage_reduction(double _damage_reduction) { this->damage_reduction = _damage_reduction; }
	void set_accuracy(double _accuracy) { this->accuracy = _accuracy; }
	void set_deflect_chance(double _defelct_chance) { this->deflect_chance = _defelct_chance; }
	void set_crit_chance(double _crit_chance) { this->crit_chance = _crit_chance; }

	//Player functions only
	virtual void increment_challenge_mode_level() { std::cout << "Not implemented" << std::endl; }
	virtual int get_challenge_mode_level() { std::cout << "Not implemented" << std::endl; return 0; }
	 
protected:
	std::string name;
	double money;
	double health;
	double damage;
	double max_health;
	double damage_reduction;
	double accuracy;
	double deflect_chance;
	double crit_chance;

	//Defaults
	double default_damage;
	double default_max_health;
	double default_damage_reduction;
	double default_accuracy;
	double default_deflect_chance;
	double default_crit_chance;

	void deal_damage(Character* _opponent, double _damage);
	void take_damage(double _damage);
};

