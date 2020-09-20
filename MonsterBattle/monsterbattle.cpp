#include "monsterbattle.h"
#include "monster.h"
#include "monstergenerator.h"
#include<iostream>
#include<random>
#include<string>

void MonsterBattle::beginMessage(const Monster& m1, const Monster& m2)
{
	std::cout << "Introducing our two combatants:\n";
	std::cout << "\nCombatant One: "; m1.print();
	std::cout << "Combatant Two: "; m2.print();
	std::cout << "\nLet the battle commence!\n";
}

void MonsterBattle::printWinner(const Monster& m1, const Monster& m2)
{
	//Generate the victory message based on whether or not m1 is dead
	//if m1 is dead, m2 is the victor, if not, m1 is the victor
	std::string victoryMessage{ (m1.isDead()) ? "\nCombatant Two: " + m2.getName() + " is the victor!\n" : "\nCombatant One: " + m1.getName() + " is the victor!\n" };
	std::cout << victoryMessage;
}

//Static function to carry out battles between two monsters
//Returns a reference to the monster that wins
Monster& MonsterBattle::Battle(Monster& m1, Monster& m2, std::mt19937& mt)
{
	//Battle start messgae
	MonsterBattle::beginMessage(m1, m2);

	int m1TurnCnt{ 0 };
	int m2TurnCnt{ 0 };

	//Determine who attacks first
	//50/50 chances so it's even
	if (MonsterGenerator::getRandomNumber(1, 100, mt) <= BattleConstants::probability_to_attack_first) //m1 gets to attack first
	{
		std::cout << m1.getName() << " attacks first!\n";
		m1TurnCnt++;
		m1.attack(m2, mt);
	}
	else //m2 gets to attack first
	{
		std::cout << m2.getName() << " attacks first!\n";
		m2TurnCnt++;
		m2.attack(m1, mt);
	}

	int turn{ 1 };

	//battle loop. Ends when either monster dies
	while (!m1.isDead() && !m2.isDead())
	{
		if (turn == 1 && m1TurnCnt == 0) //First turn and m1 hasn't attacked yet (m2 went first)
		{
			m1.attack(m2, mt);
			m1TurnCnt++;
			m2.attack(m1, mt);
			m2TurnCnt++;
			turn++;
			continue;
		}
		else if (turn == 1 && m2TurnCnt == 0) //First turn and m2 hasn't attacked yet (m1 went first)
		{
			m2.attack(m1, mt);
			m2TurnCnt++;
			m1.attack(m2, mt);
			m1TurnCnt++;
			turn++;
			continue;
		}
		else if (m1TurnCnt < m2TurnCnt) //If m2 went first, m1 will be attacking first for the rest of the battle
		{
			m1.attack(m2, mt);
			m1TurnCnt++;
			m2.attack(m1, mt);
			m2TurnCnt++;
			turn++;
			continue;
		}
		else //If m1 went first, m2 will be attacking first for the rest of the battle
		{
			m2.attack(m1, mt);
			m2TurnCnt++;
			m1.attack(m2, mt);
			m1TurnCnt++;
			turn++;
			continue;
		}

	}

	//Print the winner of the battle
	MonsterBattle::printWinner(m1, m2);

	return (m1.isDead()) ? m2 : m1;
}