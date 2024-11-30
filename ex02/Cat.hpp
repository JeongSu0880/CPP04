#ifndef CAT_HPP
# define CAT_HPP
# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal{
private:
	Brain *brain;
public:
	Cat();
	Cat(const Cat &original);
	~Cat();
	
	Cat &operator=(const Cat &original);

	void makeSound() const;
	const Brain &getBrain() const;
};

#endif