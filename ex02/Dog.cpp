#include "Dog.hpp"

Dog::Dog() : AAnimal("Dog") {
	std::cout << "Dog constructor has been called." << std::endl;

	brain = new Brain();

}

Dog::Dog(const Dog &original) : AAnimal(original.getType()) {
	std::cout << "Dog copy constructor has been called." << std::endl;

	brain = new Brain(original.getBrain());
}

Dog::~Dog() {
	std::cout << "Dog destructor has been called. " << std::endl;

	delete brain;
} 

Dog &Dog::operator=(const Dog &original) {
	if (this != &original) {
		delete brain;
		type = original.getType();
		brain = new Brain(original.getBrain());
	}

	return *this;
}

void	Dog::makeSound() const {
	std::cout << "Meong Meong!" << std::endl;
}

const Brain &Dog::getBrain() const {
	return *brain;
}