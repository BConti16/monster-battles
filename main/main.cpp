#include<iostream>
#include "../Weapon/weapon.h"

void Pause()
{
	std::cout << "Press any key to continue...";
	char ans{};
	std::cin >> ans;
}

int main()
{
	Weapon club{ Weapon::Type::club };
	club.print();

	Pause();
	return 0;
}
