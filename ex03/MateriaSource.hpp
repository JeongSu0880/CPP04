#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class IMateriaSource;

class MateriaSource : public IMateriaSource {
private: 
	AMateria *slot[4];
public:
	MateriaSource();
	MateriaSource(const MateriaSource &original);
	~MateriaSource();

	MateriaSource &operator=(const MateriaSource &original);
	void learnMateria(AMateria* m);
	AMateria* createMateria(std::string const & type);
	AMateria *getSlotItem(int idx) const;
};

#endif