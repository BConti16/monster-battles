#ifndef MONSTER_H
#define MONSTER_H

#include<string>
#include<random>
#include "weapon.h"

namespace MonsterConstants
{
	inline constexpr double max_monster_health{ 800.0 };
	inline constexpr double min_monster_health{ 500.0 };
	inline constexpr double default_monster_health{ 650.0 };
	inline constexpr double min_defense{ 100.0 };
	inline constexpr double defense_reduc_const{ 0.15 };
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
	double m_defense;
	double m_maxhp;

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
		m_maxhp = m_hp;

		m_defense = (MonsterConstants::max_monster_health - m_hp <= MonsterConstants::min_defense) ? MonsterConstants::min_defense : (MonsterConstants::max_monster_health - m_hp);
	}

	~Monster() = default;
	
	const std::string getTypeString() const;
	const std::string& getName() const;
	const double hp() const;
	void print() const;

private: //Only called internally by Monster::attack
	void reduceHealth(double damage);
	void setHealth(double health);

public:
	bool isDead() const;
	void attack(Monster& m, std::mt19937& mt);
	static void invigorate(Monster& m);

};
#endif