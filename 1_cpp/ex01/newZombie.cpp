#include "Zombie.hpp"

Zombie *Zombie::newZombie(std::string name)
{
	// std::cout << "--------newZombieStart--------" << std::endl;
	Zombie *zombie = new Zombie(name);
	// std::cout << "--------newZombieEnd--------" << std::endl;
	return (zombie);
}

std::string	nameZombie(int i)
{
	std::stringstream ss;
	ss << i << "번째 좀비";
	std::string result = ss.str();
	return result;
}


