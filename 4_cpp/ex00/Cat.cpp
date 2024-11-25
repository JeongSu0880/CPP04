#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
	std::cout << "Cat constructor has been called." << std::endl;
}

Cat::Cat(const Cat &original) : Animal(original.getType()) {
	std::cout << "Cat copy constructor has been called." << std::endl;
}

Cat::~Cat() {
	std::cout << "Cat destructor has been called. " << std::endl;
} 

Cat &Cat::operator=(const Cat &original) {
	if (this != &original) {
		this->type = original.getType();
	}

	return *this;
}

void	Cat::makeSound() const {
	std::cout << "Meow Meow" << std::endl;
}
