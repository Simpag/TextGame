#pragma once
#include "Character.h"

class Enemy : public Character
{
public:
	Enemy(std::string _name, double _health, double _damage, double _max_health, double _damage_reduction, double _accuracy, double _defelct_chance, double _crit_chance);

private:

};

