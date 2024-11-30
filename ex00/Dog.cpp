#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	std::cout << "Dog constructor has been called." << std::endl;
}

Dog::Dog(const Dog &original) : Animal(original.getType()) {
	std::cout << "Dog copy constructor has been called." << std::endl;
}

Dog::~Dog() {
	std::cout << "Dog destructor has been called. " << std::endl;
} 

Dog &Dog::operator=(const Dog &original) {
	if (this != &original) {
		this->type = original.getType();
	}

	return *this;
}

void	Dog::makeSound() const {
	std::cout << "Meong Meong!" << std::endl;
}
