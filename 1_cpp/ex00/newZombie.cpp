#include "Zombie.hpp"

Zombie *Zombie::newZombie(std::string name)
{
	// std::cout << "--------newZombieStart--------" << std::endl;
	Zombie *zombie = new Zombie(name);
	// std::cout << "--------newZombieEnd--------" << std::endl;
	return (zombie);
}
