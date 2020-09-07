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
	Monster(const Type& type, const Weapon::Type& weapon, double hp) : m_type{ type }, m_weapon{ Weapon(weapon) }
	{
		if (hp <= 0.0)
			m_hp = 100.0;
		else
			m_hp = hp;
	}
	
	const std::string getName() const;
	const double hp() const;
	void print() const;

	void reduceHealth(double damage);
	bool isDead() const;
	void attack(Monster& m);

};

#endif