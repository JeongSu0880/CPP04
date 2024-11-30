#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
	std::cout << "WrongCat constructor has been called." << std::endl;
}

WrongCat::WrongCat(const WrongCat &original) : WrongAnimal(original.getType()) {
	std::cout << "WrongCat copy constructor has been called." << std::endl;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor has been called. " << std::endl;
} 

WrongCat &WrongCat::operator=(const WrongCat &original) {
	if (this != &original) {
		this->type = original.getType();
	}

	return *this;
}

void	WrongCat::makeSound() const {
	std::cout << "Meow Meow" << std::endl;
}
