#include "monsterbattle.h"
#include "monster.h"
#include "monstergenerator.h"
#include<iostream>
#include<random>

void MonsterBattle::beginMessage(Monster& m1, Monster& m2)
{
	std::cout << "Introducing our two combatants:\n";
	std::cout << "\nCombatant One: "; m1.print();
	std::cout << "Combatant Two: "; m2.print();
	std::cout << "\nLet the battle commence!\n";
}

//Static function to carry out battles between two monsters
//Returns a reference to the monster that wins
Monster& MonsterBattle::Battle(Monster& m1, Monster& m2, std::mt19937& mt)
{
	//Battle start messgae
	MonsterBattle::beginMessage(m1, m2);

	//Determine who attacks first
	//50/50 chances so it's even
	if (MonsterGenerator::getRandomNumber(1, 100, mt) <= BattleConstants::probability_to_attack_first) //m1 gets to attack first
	{
		std::cout << m1.getName() << " attacks first!\n";
		m1.attack(m2, mt);
	}
	else //m2 gets to attack first
	{
		std::cout << m2.getName() << " attacks first!\n";
		m2.attack(m1, mt);
	}

	return m1;
}