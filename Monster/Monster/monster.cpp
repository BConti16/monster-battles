#include "monster.h"

//Returns the monster's type as a string for printing
const std::string Monster::getName() const
{
	return "stub";
}

//Returns the monster's current health points (hp)
const double Monster::hp() const
{
	return m_hp;
}

//Prints the monster's traits to the console
void Monster::print() const
{

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