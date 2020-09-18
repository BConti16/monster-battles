#include "monstergenerator.h"

Monster MonsterGenerator::generateRandomMonster(std::mt19937& mt)
{
	static const std::array<std::string, MonsterGenConstants::max_names> m_names{ "Dracula", "Shrek", "Paimon", "Scrunge", "Demen", "Tyson", "Rangor", "Nimbvar" };

	return Monster{ Monster::Type::vampire, "Dracula", Weapon::Type::claws, MonsterConstants::default_monster_health };
}