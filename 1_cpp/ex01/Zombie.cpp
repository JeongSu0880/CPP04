#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout << "no name yet" << " is created" << std::endl;
}

Zombie::Zombie(std::string name) 
{
	std::cout << name << " is created" << std::endl;
	this->name = name;
}

Zombie::~Zombie()
{
	std::cout << this->name << " is destroyed" << std::endl;
}

void Zombie::announce()
{
	std::cout << this->name << " : BraiiiiiiinnnzzzZ…" << std::endl;
}

