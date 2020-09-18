#include "monstergenerator.h"

//Returns an anonymous Monster object that is randomly generated
Monster MonsterGenerator::generateRandomMonster(std::mt19937& mt)
{
	//Setup array of names to randomly choose from
	static const std::array<std::string, MonsterGenConstants::max_names> names{ "Dracula", "Shrek", "Paimon", "Scrunge", "Demen", "Tyson", "Rangor", "Nimbvar" };

	//Setup uniform distributions to compress the random number into the range needed
	static std::uniform_int_distribution name_range{ 0, static_cast<int>(names.size()) - 1 };
	static std::uniform_int_distribution weapon_range{ 0, static_cast<int>(Weapon::Type::max_weapons) - 1 };
	static std::uniform_int_distribution monster_range{ 0, static_cast<int>(Monster::Type::max_monsters) - 1 };
	static std::uniform_int_distribution hp_range{ (int)MonsterConstants::min_monster_health, (int)MonsterConstants::max_monster_health };

	//Define the randomly generated arguments that define the monster
	auto name{ names[name_range(mt)] };
	auto monsterType{ static_cast<Monster::Type>(monster_range(mt)) };
	auto weaponType{ static_cast<Weapon::Type>(weapon_range(mt)) };
	auto hp{ static_cast<double>(hp_range(mt)) };

	//Use the generated arguments to construct the anonymous Monster object
	return Monster{ monsterType, name, weaponType, hp };
}