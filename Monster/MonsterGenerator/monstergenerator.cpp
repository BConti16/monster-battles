#include "monstergenerator.h"
#include<array>
#include<ctime>

//Returns a random number between [min, max]
int MonsterGenerator::getRandomNumber(int min, int max, std::mt19937& mt)
{
	//Create a uniform distribution from min to max
	std::uniform_int_distribution range{ min, max };

	//Generate and return a random int from [min, max]
	return range(mt);

}

//Returns an anonymous Monster object that is randomly generated
Monster MonsterGenerator::generateRandomMonster(std::mt19937& mt)
{
	//Setup array of names to randomly choose from
	static const std::array<std::string, MonsterGenConstants::max_names> names{ "Dracula", "Shrek", "Paimon", "Scrunge", "Demen", "Tyson", "Rangor", "Nimbvar" };

	//Define random parameters used to create the Monster
	//Calls getRandomNumber(int, int, std::mt19937&) to generate the random number
	auto name{ names[MonsterGenerator::getRandomNumber(0, (int)names.size() - 1, mt)] };
	auto monsterType{ static_cast<Monster::Type>(MonsterGenerator::getRandomNumber(0, (int)Monster::Type::max_monsters - 1, mt)) };
	auto weaponType{ static_cast<Weapon::Type>(MonsterGenerator::getRandomNumber(0, (int)Weapon::Type::max_weapons - 1, mt)) };
	auto hp{ static_cast<double>(MonsterGenerator::getRandomNumber(MonsterConstants::min_monster_health, MonsterConstants::max_monster_health, mt)) };

	//Use the generated arguments to construct the anonymous Monster object
	return Monster{ monsterType, name, weaponType, hp };
}