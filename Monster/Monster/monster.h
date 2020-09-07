#ifndef MONSTER_H
#define MONSTER_H

#include<string>
#include "weapon.h"

class Monster
{
public:
	enum class Type
	{
		orc,
		troll,
		vampire,
		ogre,
		demon,
		max_monsters
	};

private:
	Type m_type;
	Weapon m_weapon;
	double m_hp;

public:
	Monster(const Type& type, const Weapon::Type& weapon, double hp) : m_type{ type }, m_weapon{ Weapon(weapon) }, m_hp{ hp }
	{}


};

#endif