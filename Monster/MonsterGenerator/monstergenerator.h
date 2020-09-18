#ifndef MONSTERGENERATOR_H
#define MONSTERGENERATOR_H

#include<array>
#include<random>
#include<ctime>
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
	static Monster generateRandomMonster(std::mt19937& mt);
};

#endif