#include "Character.hpp"

Character::Character() : name("default") { 
	for (int i = 0; i < 4; i++) {
		inventory[i] = NULL;
		garbage[i] = NULL;
	}
}

Character::Character(const std::string &name) : name(name) {
	for (int i = 0; i < 4; i++) {
		inventory[i] = NULL;
		garbage[i] = NULL;
	}
}

Character::Character(const Character &original) : name(original.getName()) { 

	for (int i = 0; i < 4; i++) {
		AMateria *item = original.getInventoryItem(i);
		if (item != NULL) {
			inventory[i] = item->clone();
		}
		else {
			inventory[i] = NULL;
		}
		garbage[i] = NULL;
	}
}

Character::~Character() { 
	for (int i = 0; i < 4; i++) {
		if (inventory[i] != NULL) {	
			delete inventory[i];
		}
		if (garbage[i] != NULL) {
			delete garbage[i];
		}
	}
}

Character &Character::operator=(const Character &original) {

	if (this == &original) {
		return *this;
	}

	this->name = original.getName();

	emptyTrash();
	for (int i = 0; i < 4; i++) {
		if (this->inventory[i] != NULL) {
			delete this->inventory[i];
			this->inventory[i] = NULL;
		}
		AMateria *item = original.getInventoryItem(i);
		if (item != NULL) {
			this->inventory[i] = item->clone();
		}
	}
	return *this;
}

std::string const &Character::getName() const {
	return this->name;
}

void Character::equip(AMateria *m) {
	emptyTrash();

	int i = 0;

	while (this->inventory[i] != NULL) {
		if (i == 3) {
			delete m;
			return; //슬롯이 가득 차있는 경우
		}
		i++;
	}

	this->inventory[i] = m;
}

void Character::unequip(int idx) {
	if (!(0 <= idx && idx <= 3)) {
		return;
	}

	if (this->inventory[idx] == NULL) {
		return;
	}

	trashItem(inventory[idx]);
	inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target) {

	if (this->inventory[idx] == NULL) {
		return;
	}

	this->inventory[idx]->use(target);
}

AMateria *Character::getInventoryItem(int idx) const {

	if (!(0 <= idx && idx <= 3)) {
		return NULL;
	}

	return (this->inventory)[idx];
}

void Character::trashItem(AMateria *m) {

	int i = 0;

	while (garbage[i] != NULL) {
		i++;
	}
	garbage[i] = m;
}

void Character::emptyTrash() {
	for (int i = 0; i < 4; i++) {
		if (garbage[i] != NULL){ 
			delete garbage[i];
		}
		garbage[i] = NULL;
	}
}