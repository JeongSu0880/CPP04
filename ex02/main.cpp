#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

void leaks() {
	system("leaks ex01");
}

int main()
{
	AAnimal *dog = new Dog();

	dog->makeSound();

	delete dog;
}
