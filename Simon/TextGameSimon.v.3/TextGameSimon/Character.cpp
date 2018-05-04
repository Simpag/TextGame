#include "stdafx.h"
#include "Character.h"

double random_double(double fMin, double fMax)
{
	double f = (double)rand() / RAND_MAX;
	return fMin + f * (fMax - fMin);
}

Character::Character(std::string _name, double _health) {
	this->money = 0;
	this->name = _name;
	this->health = _health;
	this->max_health = _health;
	this->damage = 5;
	this->damage_reduction = 0;
	this->deflect_chance = 0;
	this->crit_chance = 0.3;
	this->accuracy = 0.6;
}

void Character::perform_attack(Character* _opponent, Attack_Type _type) {
	/*
	Damage = Damage * Random Percentage(50-100%)
	if crit, Damage * Random Percentage (150 - 180%)
	*/

	double _damage = 0;
	double _quick_attack_accuracy_boost = 0.4;
	double _strong_attack_accuracy_decrease = 0.2;

	switch (_type) {
	case Basic_Attack:
		if (random_double(1, 100) <= (this->accuracy * 100)) { //Accuracy
			_damage = this->damage * random_double(0.6, 1); //Attack damage is between 60 - 100% of character attack points

			if (random_double(1, 100) <= this->crit_chance * 100) {	//If the random number is less than the precentage
				_damage *= random_double(1.5, 1.8); //Random precentage between 150 - 180
			}
			deal_damage(_opponent, _damage);
		}
		else {
			std::cout << this->name << " missed! \n";
		}
		break;

	case Quick_Attack:
		if (random_double(1, 100) <= ((this->accuracy + _quick_attack_accuracy_boost) * 100)) { //Accuracy with quick attack accuracy boost
			_damage = this->damage * random_double(0.3, 0.6); //Attack damage is between 30 - 60% of character attack points

			if (random_double(1, 100) <= this->crit_chance * 100) {	//If the random number is less than the precentage
				_damage *= random_double(1.5, 1.8); //Random precentage between 150 - 180
			}
			deal_damage(_opponent, _damage);
		}
		else {
			std::cout << this->name << " missed! \n";
		}
		break;

	case Strong_Attack:
		if (random_double(1, 100) <= ((this->accuracy - _strong_attack_accuracy_decrease) * 100)) { //Accuracy
			_damage = this->damage * random_double(1, 1.5); //Attack damage is between 101 - 150% of character attack points

			if (random_double(1, 100) <= this->crit_chance * 100) {	//If the random number is less than the precentage
				_damage *= random_double(1.5, 1.8); //Random precentage between 151 - 180
			}
			deal_damage(_opponent, _damage);
		}
		else {
			std::cout << this->name << " missed! \n";
		}
		break;
	}
}

void Character::deal_damage(Character* _opponent, double _damage) {
	_opponent->take_damage(_damage);
}

void Character::take_damage(double _damage) {
	/*
	Health -= Opponent.Damage * (100% - Total Damage Reduction * Random Percentage(51 - 100 % ))
	damage_reduction 
	deflect_chance
	*/
	if (random_double(1, 100) <= (100 - this->deflect_chance * 100)) { //Deflect chance
		double _total_damage = _damage * (1 - (this->damage_reduction * random_double(0.5, 1)));
		this->health -= _total_damage;
		std::cout << this->name << " got hit for " << _total_damage << " damage points!\n";
	}
	else {
		std::cout << this->name << " dodged the attack!\n";
	}
}

void Character::add_health(double _amount) {
	this->health += _amount;

	if (this->health > this->max_health)
		this->health = this->max_health;
}