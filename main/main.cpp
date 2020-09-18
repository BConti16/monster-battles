#include<iostream>
#include "weapon.h"
#include "monster.h"

void Pause()
{
	std::cout << "Press any key to continue... ";
	char ans{};
	std::cin >> ans;
}

int main()
{
	Weapon club{ Weapon::Type::club };
	club.print();

	std::cout << '\n';

	Monster demon{ Monster::Type::demon, "Dracula", Weapon::Type::claws, 600.0 };
	demon.print();

	Pause();
	return 0;
}
