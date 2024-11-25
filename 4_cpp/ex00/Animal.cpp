#include "Animal.hpp"

Animal::Animal() : type("None") {
	std::cout << "Animal has been created." << std::endl;
}

Animal::Animal(const std::string &name) : type(name) { 
	std::cout << "Animal has been created." << std::endl;
}

Animal::Animal(const Animal &origianl) {
	std::cout << "Animal copy constructor has been called." << std::endl;
	*this = origianl;
}

Animal &Animal::operator=(const Animal &original) {
	if (this != &original) {
		this->type = original.getType();
	}

	return *this;
}

Animal::~Animal() {
	std::cout << "Animal destructor has been called." << std::endl;
}

std::string Animal::getType() const {
	return this->type;
}

void Animal::makeSound() const {
	std::cout << "An animal makes no sound...." << std::endl;
}