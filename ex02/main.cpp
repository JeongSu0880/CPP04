#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

void leaks() {
	system("leaks ex01");
}

int main()
{
	//아래는 컴파일 에러
	// AAnimal *animal = new AAnimal(); 

	AAnimal *dog = new Dog();

	dog->makeSound();

	delete dog;
}
