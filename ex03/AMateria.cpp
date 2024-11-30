#include "AMateria.hpp"

AMateria::AMateria() { }

AMateria::AMateria(std::string const &type) : type(type) { }

AMateria::~AMateria() { }

AMateria::AMateria(const AMateria &original) {
	*this = original;
}

AMateria &AMateria::operator=(const AMateria &original) {
	if (this != &original) {
		this->type = original.getType();
	}

	return *this;
}

std::string const &AMateria::getType() const {
	return this->type;
}

void AMateria::use(ICharacter &target) {
	std::cout << "Cannot use AMateria. " << "Nothing happens to " << target.getName() << std::endl;
}