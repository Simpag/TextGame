#pragma once
#include "stdafx.h"
#include "Enemy.h"

enum ChallengerName { Beorn, Melker, Tranto, Orval, Ulysses, Columbus, Osborne, Gunner, Titus, Lazarus, Earl, Horace, Ezekiel, Phoenix, Thor, Ra, Ares, Cronus, Bor, SurturtheFireDemon, Joakim };

//Enemy(string _name, double _health, double _max_health, double _damage, double _damage_reduction, double _accuracy, double _deflect_chance, double _crit_chance, int _worth)

std::vector<Enemy*> challenge_mode_enemy_vector {
	new Enemy("Beorn", 22, 22, 4, 0.01, 0.4, 0.2, 0.2, 1000),
	new Enemy("Melker", 44, 44, 8, 0.02, 0.4, 0.2, 0.2, 2000),
	new Enemy("Tranto", 88, 88, 16, 0.03, 0.4, 0.2, 0.2, 4000),
	new Enemy("Orval", 176, 176, 32, 0.04, 0.4, 0.2, 0.2, 8000),
	new Enemy("Ulysses", 352, 352, 64, 0.05, 0.4, 0.2, 0.2, 16000),
	new Enemy("Columbus", 704, 704, 128, 0.06, 0.6, 0.2, 0.2, 32000),
	new Enemy("Osborne", 1408, 1408, 256, 0.07, 0.6, 0.2, 0.2, 64000),
	new Enemy("Gunner", 2816, 2816, 512, 0.08, 0.6, 0.2, 0.2, 128000),
	new Enemy("Titus", 5632, 5632, 1024, 0.09, 0.7, 0.2, 0.2, 256000),
	new Enemy("Lazarus",11264, 11264, 2048, 0.1, 0.7, 0.2, 0.2, 512000),
	new Enemy("Earl", 22528, 22528, 4096, 0.11, 0.7, 0.2, 0.2, 1240000),
	new Enemy("Horace", 45056, 45056, 8192, 0.12, 0.8, 0.2, 0.2, 2480000),
	new Enemy("Ezekiel", 90112, 90112, 16384, 0.13, 0.8, 0.2, 0.2, 5960000),
	new Enemy("Phoenix", 180224, 180224, 32768, 0.14, 0.8, 0.2, 0.2, 11920000),
	new Enemy("Thor", 360448, 360448, 65536, 0.15, 0.9, 0.2, 0.2, 23840000),
	new Enemy("Ra", 720896, 720896, 131072, 0.16, 0.9, 0.2, 0.2, 47680000),
	new Enemy("Ares", 1441792, 1441792, 262144, 0.17, 0.9, 0.2, 0.2, 95360000),
	new Enemy("Cronus", 2883584, 2883584, 525288, 0.18, 1, 0.2, 0.2, 190720000),
	new Enemy("Bor", 5767168, 5767168, 1048576, 0.19, 1, 0.2, 0.2, 381440000),
	new Enemy("Surtur the Fire Demon", 5767168*2, 5767168*2, 1048576*2, 0.2, 1, 0.2, 0.2, 762880000),
	new Enemy("Joakim", 12000000, 12000000, 2100000, 0.21, 1, 0.21, 0.21, 9999999999999999999)
};

