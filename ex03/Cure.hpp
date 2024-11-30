#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>
# include "AMateria.hpp"

class Cure : public AMateria{
public :
	Cure();
	Cure(const Cure &origianl);
	~Cure();

	Cure &operator=(const Cure &original);

	AMateria *clone() const;
	void use(ICharacter &target);
};

#endif