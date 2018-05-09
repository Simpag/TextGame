#pragma once
#include "stdafx.h"
#include "Enemy.h"

enum ChallengerName { Beorn, Melker, Tranto, Orval, Ulysses, Columbus, Osborne, Gunner, Titus, Lazarus, Earl, Horace, Ezekiel, Phoenix, Thor, Ra, Ares, Cronus, Bor, SurturTheFireDemon };

//Enemy(string _name, double _health, double _max_health, double _damage, double _damage_reduction, double _accuracy, double _deflect_chance, double _crit_chance, int _worth)

std::vector<Enemy*> challenge_mode_enemy_vector{
	new Enemy("Beorn", 22, 4, 22, 0.01, 0.4, 0.2, 0.2, 500),
	new Enemy("Melker", 44, 8, 44, 0.02, 0.4, 0.2, 0.2, 500),
	new Enemy("Tranto", 88, 16, 88, 0.03, 0.4, 0.2, 0.2, 500),
	new Enemy("Orval", 176, 32, 176, 0.04, 0.4, 0.2, 0.2, 500),
	new Enemy("Ulysses", 352, 64, 352, 0.05, 0.4, 0.2, 0.2, 500),
	new Enemy("Columbus", 704, 128, 704, 0.06, 0.6, 0.2, 0.2, 500),
	new Enemy("Osborne", 1408, 256, 1408, 0.07, 0.6, 0.2, 0.2, 500),
	new Enemy("Gunner", 2816, 512, 2816, 0.08, 0.6, 0.2, 0.2, 500),
	new Enemy("Titus", 5632, 1024, 5632, 0.09, 0.7, 0.2, 0.2, 500),
	new Enemy("Lazarus",11264, 2048, 11264, 0.1, 0.7, 0.2, 0.2, 500),
	new Enemy("Earl", 22528, 4096, 22528, 0.11, 0.7, 0.2, 0.2, 500),
	new Enemy("Horace", 45056, 8192, 45056, 0.12, 0.8, 0.2, 0.2, 500),
	new Enemy("Ezekiel", 90112, 16384, 90112, 0.13, 0.8, 0.2, 0.2, 500),
	new Enemy("Phoenix", 180224, 32768, 180224, 0.14, 0.8, 0.2, 0.2, 500),
	new Enemy("Thor", 360448, 65536, 360448, 0.15, 0.9, 0.2, 0.2, 500),
	new Enemy("Ra", 720896, 131072, 720896, 0.16, 0.9, 0.2, 0.2, 500),
	new Enemy("Ares", 1441792, 262144, 1441792, 0.17, 0.9, 0.2, 0.2, 500),
	new Enemy("Cronus", 2883584, 524288, 2883584, 0.18, 1, 0.2, 0.2, 500),
	new Enemy("Bor", 5767168, 1048576, 5767168, 0.19, 1, 0.2, 0.2, 500),
	new Enemy("Surtur the Fire Demon", 12000000, 2100000, 12000000, 0.2, 1, 0.2, 0.2, 500),
};

