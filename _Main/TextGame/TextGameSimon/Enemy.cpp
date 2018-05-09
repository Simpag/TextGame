#include "stdafx.h"
#include "Enemy.h"

Enemy::Enemy(std::string _name, double _health, double _max_health, double _damage, double _damage_reduction, double _accuracy, double _deflect_chance, double _crit_chance, int _worth) : Character(_name, _health, _max_health, _damage, _damage_reduction, _accuracy, _deflect_chance, _crit_chance) {
	this->worth = _worth;
}