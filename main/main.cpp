#include<iostream>
#include<string>
#include<ctime>
#include<random>
#include "weapon.h"
#include "monster.h"
#include "monstergenerator.h"

void Pause()
{
	std::cout << "\nPress enter to continue... ";
	std::string ans{};
	std::getline(std::cin, ans);
}

int main()
{
	//Define and seed random number generator
	std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };

	Weapon club{ Weapon::Type::club };
	club.print();

	std::cout << '\n';

	std::cout << "Manual Monster\n";
	Monster demon{ Monster::Type::demon, "Dracula", Weapon::Type::claws, 600.0 };
	demon.print();

	std::cout << '\n';

	std::cout << "Random Monster\n";
	Monster m{ MonsterGenerator::generateRandomMonster(mt) };
	m.print();

	Pause();
	return 0;
}
