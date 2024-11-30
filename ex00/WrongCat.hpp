#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP
# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal{
public:
	WrongCat();
	WrongCat(const WrongCat &original);
	~WrongCat();
	
	WrongCat &operator=(const WrongCat &original);

	void makeSound() const;
};

#endif