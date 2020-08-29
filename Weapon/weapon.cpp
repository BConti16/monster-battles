#include "weapon.h"
#include<iostream>

//Initializes Weapon class' members
void Weapon::init()
{
	switch (m_type)
	{
	case Type::spear:
		m_damage = 62.0;
		m_attackspeed = 0.61;
		break;
	case Type::sword:
		m_damage = 75.0;
		m_attackspeed = 0.75;
		break;
	case Type::claws:
		m_damage = 30.0;
		m_attackspeed = 0.32;
		break;
	case Type::axe:
		m_damage = 85.0;
		m_attackspeed = 0.93;
		break;
	case Type::club:
		m_damage = 108.0;
		m_attackspeed = 1.2;
		break;
	case Type::flail:
		m_damage = 92.0;
		m_attackspeed = 1.0;
		break;
	default:
		m_damage = 0.0;
		m_attackspeed = 0.0;
		break;
	}

	if (m_attackspeed == 0)
	{
		m_dps = m_damage / (m_attackspeed + 1);
	}
	else
	{
		m_dps = m_damage / m_attackspeed;
	}
}

const double Weapon::damage() const
{
	return m_damage;
}

const double Weapon::attackspeed() const
{
	return m_attackspeed;
}

const double Weapon::dps() const
{
	return m_dps;
}

const std::string Weapon::getWeaponName() const
{
	switch (m_type)
	{
	case Type::spear:
		return "Spear";
	case Type::sword:
		return "Sword";
	case Type::claws:
		return "Claws";
	case Type::axe:
		return "Axe";
	case Type::club:
		return "Club";
	case Type::flail:
		return "Flail";
	default:
		return "???";
	}
}

//Prints the weapon characteristics to the screen
void Weapon::print() const
{
	std::cout << "Type: " << getWeaponName() << ", Damage: " << m_damage << ", " << "Attack Speed: " << m_attackspeed << ", "
		<< "DPS: " << m_dps << '\n';
}

