#include<iostream>
#include<string>
#include<ctime>
#include<random>
#include "weapon.h"
#include "monster.h"
#include "monstergenerator.h"
#include "monsterbattle.h"

int main()
{
	//Define and seed random number generator
	std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };

	Monster m1{ MonsterGenerator::generateRandomMonster(mt) };
	Monster m2{ MonsterGenerator::generateRandomMonster(mt) };

	while (m1.getName() == m2.getName())
	{
		m2 = MonsterGenerator::generateRandomMonster(mt);
	}

	MonsterBattle::Battle(m1, m2, mt);

	MonsterBattle::Pause();
	return 0;
}
