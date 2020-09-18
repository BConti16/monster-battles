#ifndef MONSTERGENERATOR_H
#define MONSTERGENERATOR_H

#include<random>
#include<string>
#include "monster.h"
#include "weapon.h"

namespace MonsterGenConstants
{
	inline constexpr std::size_t max_names{ 8 };
}

class MonsterGenerator
{
public:
	static int getRandomNumber(int min, int max, std::mt19937& mt);
	static Monster generateRandomMonster(std::mt19937& mt);
};

#endif