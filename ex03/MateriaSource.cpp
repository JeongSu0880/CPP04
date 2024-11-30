#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; i++) {
		slot[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource &original) {
	for (int i = 0; i < 4; i++) {
		AMateria *item = original.getSlotItem(i);
		if (item != NULL) {
			slot[i] = item->clone();
		} else {
			slot[i] = NULL;
		}
	}
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++) {
		if (slot[i] != NULL) {
			delete slot[i];
		}
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource &original) {

	if (this == &original) {
		return *this;
	}
	for (int i = 0; i < 4; i++) {
		if (slot[i] != NULL) {
			delete slot[i];
		}
		
		AMateria *item = original.getSlotItem(i);
		if (item != NULL) {
			slot[i] = item->clone();
		}
	}
	return *this;
}

AMateria *MateriaSource::getSlotItem(int idx) const {

	if (!(0 <= idx && idx <= 3)) {
		return NULL;
	}

	return slot[idx];
}

void MateriaSource::learnMateria(AMateria *m) {
	int i = 0;

	while (slot[i] != NULL) {
		if (i == 3) 
			return;
		i++;
	}

	slot[i] = m;
}

AMateria *MateriaSource::createMateria(std::string const &type) {
	
	for (int i = 0; i < 4; i++) {
		if (slot[i] != NULL && slot[i]->getType() == type) {
			return slot[i]->clone();
		}
	}

	return NULL;
}