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
	static void Pause();
	static Monster& Battle(Monster& m1, Monster& m2, std::mt19937& mt);
	static bool nextFight();

private:
	static void beginMessage(const Monster& m1, const Monster& m2);
	static void printWinner(const Monster& m1, const Monster& m2);
	static void displayHealth(const Monster& m1, const Monster& m2);
	
};

#endif
