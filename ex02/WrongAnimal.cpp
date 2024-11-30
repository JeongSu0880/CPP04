#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("None") {
	std::cout << "WrongAnimal has been created." << std::endl;
}

WrongAnimal::WrongAnimal(const std::string &name) : type(name) { 
	std::cout << "WrongAnimal has been created." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &origianl) {
	std::cout << "WrongAnimal copy constructor has been called." << std::endl;
	*this = origianl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &origianl) {
	if (this != &origianl) {
		type = origianl.getType();
	}

	return *this;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor has been called." << std::endl;
}

std::string WrongAnimal::getType() const {
	return type;
}

void WrongAnimal::makeSound() const {
	std::cout << "An WrongAnimal makes no sound...." << std::endl;
}