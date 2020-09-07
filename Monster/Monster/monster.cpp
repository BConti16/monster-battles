#include "monster.h"
#include<iostream>

//Returns the monster's type as a string for printing
const std::string Monster::getName() const
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

//Returns the monster's current health points (hp)
const double Monster::hp() const
{
	return m_hp;
}

//Prints the monster's traits to the console
void Monster::print() const
{
	std::cout << getName() << ": Health - " << m_hp << ", Weapon - " << m_weapon.getWeaponName() << ", DPS - " << m_weapon.dps() << '\n';
}

//Reduces the monster's health by the amount specified in the argument
void Monster::reduceHealth(double damage)
{

}

//Returns true if the monster's health has reached or fallen below 0.0, and false otherwise
bool Monster::isDead() const
{
	if (m_hp <= 0.0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//This monster attacks the monster specified by the argument, reducing it's health according to the weapon held
void Monster::attack(Monster& m)
{

}