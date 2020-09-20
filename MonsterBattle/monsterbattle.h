#ifndef MONSTERBATTLE_H
#define MONSTERBATTLE_H

#include<random>
#include "monster.h"

class MonsterBattle
{
public:
	static Monster& Battle(Monster& m1, Monster& m2, std::mt19937& mt);
};

#endif
