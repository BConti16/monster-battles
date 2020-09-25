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
//If less than 0 hp, just return 0 (for neatness)
const double Monster::hp() const
{
	return (m_hp <= 0.0) ? 0.0 : m_hp;
}

//Prints the monster's traits to the console
void Monster::print() const
{
	std::cout << getName() << " the " << getTypeString() << ": Health - " << m_hp << ", Defense - " << m_defense << ", Weapon - " << m_weapon.getWeaponName() << ", DPS - " << m_weapon.dps() << '\n';
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

	//If attacker is currently dead, they can't attack
	if (this->isDead())
		return;

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

	damageDealt -= (m.m_defense * MonsterConstants::defense_reduc_const); //reduce damage dealt by the attacked monster's effective defense

	std::cout << getName() << " attacks " << m.getName() << " for " << damageDealt << " damage!\n";
	m.reduceHealth(damageDealt);
}

void Monster::setHealth(double health)
{
	m_hp = health;
}

//Static method to reset a monster's health back to its original max value
void Monster::invigorate(Monster& m)
{
	m.setHealth(m.m_maxhp);
}