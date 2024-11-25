#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain has been created." << std::endl;
}

Brain::Brain(const Brain &origianl) {
	std::cout << "Brain copy constructor has been called." << std::endl;
	*this = origianl;
}

Brain &Brain::operator=(const Brain &original) {
	if (this != &original) {
		for (int i = 0; i < 100; ++i) {
			ideas[i] = original.ideas[i];
		}
	}

	return *this;
}

Brain::~Brain() {
	std::cout << "Brain destructor has been called." << std::endl;
}


std::string *Brain::getIdeas() {
	return ideas;
}