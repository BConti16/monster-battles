#ifndef MONSTERBATTLE_H
#define MONSTERBATTLE_H

#include<random>
#include "monster.h"

namespace BattleConstants
{
	inline constexpr int probability_to_attack_first{ 50 };
}

class MonsterBattle
{
public:
	static void beginMessage(Monster& m1, Monster& m2);
	static Monster& Battle(Monster& m1, Monster& m2, std::mt19937& mt);
};

#endif
