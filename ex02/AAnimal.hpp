#ifndef AANIMAL_HPP
# define AANIMAL_HPP
# include <iostream>

class AAnimal {
protected:
	std::string type;
public:
	AAnimal();
	AAnimal(const std::string &name);
	AAnimal(const AAnimal &original);
	virtual ~AAnimal();

	AAnimal &operator=(const AAnimal &original);

	virtual void makeSound() const = 0;

	std::string getType() const;
};

#endif
