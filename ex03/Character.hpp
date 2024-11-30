#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

class Character : public ICharacter {
private:
	AMateria *inventory[4];
	AMateria *garbage[4];
	std::string name;

	void trashItem(AMateria *m);
	void emptyTrash();

public: 
	Character();
	Character(const Character &original);
	Character(const std::string &name);
	~Character();

	Character &operator=(const Character &original);

	std::string const &getName() const;
	void equip(AMateria *m);
	void unequip(int idx);
	void use(int idx, ICharacter &target);

	AMateria *getInventoryItem(int idx) const;
};

#endif
