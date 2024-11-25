#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	std::cout << "Dog constructor has been called." << std::endl;

	this->brain = new Brain();

}

Dog::Dog(const Dog &original) : Animal(original.getType()) {
	std::cout << "Dog copy constructor has been called." << std::endl;

	this->brain = new Brain(original.getBrain());
}

Dog::~Dog() {
	std::cout << "Dog destructor has been called. " << std::endl;

	delete brain;
} 

Dog &Dog::operator=(const Dog &original) {
	if (this != &original) {
		delete this->brain;
		this->type = original.getType();
		this->brain = new Brain(original.getBrain());
	}

	return *this;
}

void	Dog::makeSound() const {
	std::cout << "Meong Meong!" << std::endl;
}

const Brain &Dog::getBrain() const {
	return *this->brain;
}