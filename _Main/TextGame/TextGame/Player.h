#pragma once
#include "Character.h"
class Player : public Character
{
public:
	Player(std::string _name, double _health, double _max_health, double _damage, double _damage_reduction, double _accuracy, double _defelct_chance, double _crit_chance);

	void increment_challenge_mode_level() { this->challenge_mode_level++; }
	int get_challenge_mode_level() { return this->challenge_mode_level; }
	void set_challenge_mode_level(int _level) { challenge_mode_level = _level; }

protected:
	//Only used for the player
	int challenge_mode_level;

};

