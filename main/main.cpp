#include<iostream>
#include "../Weapon/weapon.h"

int main()
{
	Weapon club{ Weapon::Type::club };
	std::cout << club.getWeaponName();
	club.print();

	return 0;
}
