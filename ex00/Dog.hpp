#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal{
public:
	Dog();
	~Dog();
	Dog(const Dog &original);
	
	Dog &operator=(const Dog &original);

	void makeSound() const;
};

#endif