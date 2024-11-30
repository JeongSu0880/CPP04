#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {};

Cure::Cure(const Cure &original) : AMateria("cure") {
	*this = original;
}

Cure::~Cure() {}

Cure &Cure::operator=(const Cure &original) {
	if (this != &original) {
		type = original.getType();
	}

	return *this;
}

AMateria *Cure::clone() const {
	return new Cure();
}

void Cure::use(ICharacter &target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}