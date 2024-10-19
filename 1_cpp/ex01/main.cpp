#include "Zombie.hpp"

// void leaks()
// {
// 	system("leaks ex00");
// }

int main()
{
	// atexit(leaks);

	Zombie *zombies;

	zombies = Zombie::zombieHorde(8, "zomm");
	for (int i = 0; i < 8; i++)
	{
		std::cout << i + 1 << "번째 좀비" << std::endl;
		zombies[i].announce();
	}

	delete[] zombies;
}