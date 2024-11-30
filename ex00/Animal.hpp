#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>

class Animal {
protected:
	std::string type;
public:
	Animal();
	Animal(const std::string &name);
	Animal(const Animal &original);
	virtual ~Animal();

	Animal &operator=(const Animal &original);

	virtual void makeSound() const;

	std::string getType() const;
};

#endif
