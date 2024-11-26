#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal{
private:
	Brain *brain;
public:
	Dog();
	~Dog();
	Dog(const Dog &original);
	
	Dog &operator=(const Dog &original);

	void makeSound() const;
	const Brain &getBrain() const;
};

#endif