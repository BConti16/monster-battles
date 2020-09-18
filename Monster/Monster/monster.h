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
	std::string m_name;
	Weapon m_weapon;
	double m_hp;

public:
	Monster(const Type& type, const std::string& name, const Weapon::Type& weapon, double hp) : m_type{ type }, m_name{ name }, m_weapon{ Weapon(weapon) }
	{
		if (hp <= 0.0)
			m_hp = 650.0; //default health if invalid amount passed in
		else
			m_hp = hp;
	}

	~Monster() = default;
	
	const std::string getTypeString() const;
	const std::string& getName() const;
	const double hp() const;
	void print() const;

private: //Only called internally by Monster::attack
	void reduceHealth(double damage);

public:
	bool isDead() const;
	void attack(Monster& m);

};

#endif