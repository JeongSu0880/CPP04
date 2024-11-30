#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
	std::cout << "Cat constructor has been called." << std::endl;

	this->brain = new Brain();
}

Cat::Cat(const Cat &original) : Animal(original.getType()) {
	std::cout << "Cat copy constructor has been called." << std::endl;

	this->brain = new Brain(original.getBrain());
}

Cat::~Cat() {
	std::cout << "Cat destructor has been called. " << std::endl;

	delete brain;
} 

Cat &Cat::operator=(const Cat &original) {
	if (this != &original) {
		delete this->brain;
		this->type = original.getType();
		this->brain = new Brain(original.getBrain());
	}

	return *this;
}

void	Cat::makeSound() const {
	std::cout << "Meow Meow" << std::endl;
}

const Brain &Cat::getBrain() const {
	return *this->brain;
}