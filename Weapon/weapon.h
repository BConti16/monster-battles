#ifndef WEAPON_H
#define WEAPON_H
#include<string>

class Weapon
{
public:
	enum class Type
	{
		spear,
		sword,
		club,
		claws,
		axe,
		flail,
		max_weapons
	};

private:
	Type m_type{};
	double m_damage{};
	double m_attackspeed{};
	double m_dps{};

public:
	Weapon(Type type) : m_type{ type }
	{
		initDamage();
		initAttackSpeed();
		initDPS();
	}
	
private:
	void initDamage();
	void initAttackSpeed();
	void initDPS();

public:
	const double& damage() const;
	const double& attackspeed() const;
	const double& dps() const;

	const std::string getWeaponName() const;
	void print() const;
};

#endif