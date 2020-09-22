#include "monster.h"
#include "weapon.h"
#include "monstergenerator.h"
#include<iostream>

//Returns the monster's type as a string for printing
const std::string Monster::getTypeString() const
{
	switch (m_type)
	{
	case Type::orc:
		return "Orc";
	case Type::troll:
		return "Troll";
	case Type::vampire:
		return "Vampire";
	case Type::ogre:
		return "Ogre";
	case Type::demon:
		return "Demon";
	default:
		return "???";
	}
}

//Returns the monster's name
const std::string& Monster::getName() const
{
	return m_name;
}

//Returns the monster's current health points (hp)
const double Monster::hp() const
{
	return m_hp;
}

//Prints the monster's traits to the console
void Monster::print() const
{
	std::cout << getName() << " the " << getTypeString() << ": Health - " << m_hp << ", Weapon - " << m_weapon.getWeaponName() << ", DPS - " << m_weapon.dps() << '\n';
}

//Reduces the monster's health by the amount specified in the argument
void Monster::reduceHealth(double damage)
{
	if (this->isDead())
	{
		return;
	}

	m_hp -= damage;
}

//Returns true if the monster's health has reached or fallen below 0.0, and false otherwise
bool Monster::isDead() const
{
	return m_hp <= 0.0;
}

//This monster attacks the monster specified by the argument, reducing it's health according to the weapon held
void Monster::attack(Monster& m, std::mt19937& mt)
{
	if (this == &m)
	{
		std::cout << getName() << " cannot attack itself!\n";
		return;
	}

	//30% chance to miss the attack
	static const int missChance{ 30 };
	if (MonsterGenerator::getRandomNumber(1, 100, mt) <= missChance)
	{
		std::cout << getName() << " missed!\n";
		return;
	}

	//20% chance for a critical hit
	static const int criticalHitChance{ 20 };
	double damageDealt;
	if (MonsterGenerator::getRandomNumber(1, 100, mt) <= criticalHitChance)
	{
		std::cout << "It's a critical hit!!\n";
		damageDealt = this->m_weapon.dps() * WeaponConstants::critical_hit_multiplier;
	}
	else
	{
		damageDealt = this->m_weapon.dps();
	}

	std::cout << getName() << " attacks " << m.getName() << " for " << damageDealt << " damage!\n";
	m.reduceHealth(damageDealt);
}