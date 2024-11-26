#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP
# include <iostream>

class WrongAnimal {
protected:
	std::string type;
public:
	WrongAnimal();
	WrongAnimal(const std::string &name);
	WrongAnimal(const WrongAnimal &original);
	virtual ~WrongAnimal();

	WrongAnimal &operator=(const WrongAnimal &original);

	void makeSound() const;

	std::string getType() const;
};

#endif
