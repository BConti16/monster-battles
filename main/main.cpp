#include<iostream>
#include "../Weapon/weapon.h"

int main()
{
	Weapon sword{ Weapon::Type::sword };
	sword.print();
	return 0;
}
