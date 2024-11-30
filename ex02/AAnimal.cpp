#include "AAnimal.hpp"

AAnimal::AAnimal() : type("None") {
	std::cout << "AAnimal has been created." << std::endl;
}

AAnimal::AAnimal(const std::string &name) : type(name) { 
	std::cout << "AAnimal has been created." << std::endl;
}

AAnimal::AAnimal(const AAnimal &origianl) {
	std::cout << "AAnimal copy constructor has been called." << std::endl;
	*this = origianl;
}

AAnimal &AAnimal::operator=(const AAnimal &origianl) {
	if (this != &origianl) {
		type = origianl.getType();
	}

	return *this;
}

AAnimal::~AAnimal() {
	std::cout << "AAnimal destructor has been called." << std::endl;
}

std::string AAnimal::getType() const {
	return this->type;
}
