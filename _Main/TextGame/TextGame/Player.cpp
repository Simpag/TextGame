#include "stdafx.h"
#include "Player.h"


Player::Player(std::string _name, double _health, double _max_health, double _damage, double _damage_reduction, double _accuracy, double _defelct_chance, double _crit_chance) : Character(_name, _health, _max_health, _damage, _damage_reduction, _accuracy, _defelct_chance, _crit_chance)
{
	challenge_mode_level = 0;
}