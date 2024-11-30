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

	name = original.getName();

	emptyTrash();
	for (int i = 0; i < 4; i++) {
		if (inventory[i] != NULL) {
			delete inventory[i];
			inventory[i] = NULL;
		}
		AMateria *item = original.getInventoryItem(i);
		if (item != NULL) {
			inventory[i] = item->clone();
		}
	}
	return *this;
}

std::string const &Character::getName() const {
	return name;
}

void Character::equip(AMateria *m) {
	emptyTrash();

	int i = 0;

	while (inventory[i] != NULL) {
		if (i == 3) {
			delete m;
			return; //슬롯이 가득 차있는 경우
		}
		i++;
	}

	inventory[i] = m;
}

void Character::unequip(int idx) {
	if (!(0 <= idx && idx <= 3)) {
		return;
	}

	if (inventory[idx] == NULL) {
		return;
	}

	trashItem(inventory[idx]);
	inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target) {

	if (inventory[idx] == NULL) {
		return;
	}

	inventory[idx]->use(target);
}

AMateria *Character::getInventoryItem(int idx) const {

	if (!(0 <= idx && idx <= 3)) {
		return NULL;
	}

	return (inventory)[idx];
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