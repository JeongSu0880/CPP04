#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

void leaks() {
	system("leaks ex01");
}

int main()
{
	// Animal animal; 에러!

	AAnimal *dog = new Dog();

	dog->makeSound();

	delete dog;
}
//이게 되는 이유.