#include "Zombie.hpp"

void Zombie::randomChump(std::string name)
{
	// std::cout << "--------randomChumpStart--------" << std::endl;
	Zombie zombie = Zombie(name);
	zombie.announce();
	// std::cout << "--------randomChumpEnd--------" << std::endl;
}