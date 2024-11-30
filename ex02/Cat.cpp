#include "Cat.hpp"

Cat::Cat() : AAnimal("Cat") {
	std::cout << "Cat constructor has been called." << std::endl;

	brain = new Brain();
}

Cat::Cat(const Cat &original) : AAnimal(original.getType()) {
	std::cout << "Cat copy constructor has been called." << std::endl;

	brain = new Brain(original.getBrain());
}

Cat::~Cat() {
	std::cout << "Cat destructor has been called. " << std::endl;

	delete brain;
} 

Cat &Cat::operator=(const Cat &original) {
	if (this != &original) {
		delete brain;
		type = original.getType();
		brain = new Brain(original.getBrain());
	}

	return *this;
}

void	Cat::makeSound() const {
	std::cout << "Meow Meow" << std::endl;
}

const Brain &Cat::getBrain() const {
	return *brain;
}