#include<iostream>
#include "../Weapon/weapon.h"

int main()
{
	Weapon spear{ Weapon::Type::spear };
	spear.print();
	return 0;
}
