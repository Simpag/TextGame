#include "stdafx.h"
#include "Character.h"


Character::Character(std::string _name, double _health) {
	this->money = 0;
	this->name = _name;
	this->health = _health;
	this->max_health = _health;
	this->damage = 5;
	this->damage_reduction = 0;
	this->deflect_chance = 0.1;
	this->crit_chance = 0.3;
	this->accuracy = 0.6;
}

void Character::perform_attack(Character* _opponent, int _type) {
	/*
	Damage = Damage * Random Percentage(50-100%)
	if crit, Damage * Random Percentage (150 - 180%)
	*/

	enum Attack_Type { Basic, Qucik, Strong };

	//Rand gives a number from 0 to 49 then plus 51. Then / 100 for precentage
	double _damage = this->damage * (rand() % 50 + 51) / 100;

	if ((1 / (rand() % 100 + 1)) <= this->crit_chance) {
		_damage *= (rand() % 30 + 151) / 100; //Random precentage between 150 - 180
	}

	deal_damage(_opponent, _damage);
}

void Character::deal_damage(Character* _opponent, double _damage) {
	_opponent->take_damage(_opponent, _damage);
}

void Character::take_damage(Character* _opponent, double _damage) {
	/*
	Health -= Opponent.Damage * (100% - Total Damage Reduction * Random Percentage(30 - 100 % ))
	*/
	double _total_damage = _damage * ((100 - (this->damage_reduction * ((rand() % 70 + 31) / 100)) )/100);
	this->health -= _total_damage;
	std::cout << _opponent->get_name() << " got hit for " << _total_damage << " damage points!\n";
}

void Character::add_health(double _amount) {
	this->health += _amount;

	if (this->health > this->max_health)
		this->health = this->max_health;
}