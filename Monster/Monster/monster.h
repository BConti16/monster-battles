#ifndef MONSTER_H
#define MONSTER_H

#include<string>
#include "weapon.h"

namespace MonsterConstants
{
	inline constexpr double max_monster_health{ 800.0 };
	inline constexpr double min_monster_health{ 500.0 };
	inline constexpr double default_monster_health{ 650.0 };
}

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
		{
			m_hp = MonsterConstants::default_monster_health; //default health if invalid amount passed in
		}
		else if (hp > MonsterConstants::max_monster_health)
		{
			m_hp = MonsterConstants::max_monster_health; //set to the limit health if upper bound is exceeded
		}
		else if (hp < MonsterConstants::min_monster_health)
		{
			m_hp = MonsterConstants::min_monster_health; //set to limit health if lower bound is reached
		}
		else
		{
			m_hp = hp;
		}
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