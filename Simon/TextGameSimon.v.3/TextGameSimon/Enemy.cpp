#include "stdafx.h"
#include "Enemy.h"

Enemy::Enemy(std::string _name, double _health, double _damage, double _max_health, double _damage_reduction, double _accuracy, double _defelct_chance, double _crit_chance) : Character(_name, _health) {
	this->name = _name;
	this->health = _health;
	this->max_health = _health;
	this->damage = _damage;
	this->damage_reduction = _damage_reduction;
	this->deflect_chance = _defelct_chance;
	this->crit_chance = _crit_chance;
	this->accuracy = _accuracy;
}