#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {};

Ice::Ice(const Ice &original) : AMateria("ice") {
	*this = original;
}

Ice::~Ice() {}

Ice &Ice::operator=(const Ice &original) {
	if (this != &original) {
		type = original.getType();
	}

	return *this;
}

AMateria *Ice::clone() const {
	return new Ice();
}

void Ice::use(ICharacter &target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}