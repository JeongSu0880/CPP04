#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

void leaks() {
	system("leaks ex01");
}

int main()
{
	Animal *arr[10];

	for (int i = 0; i < 5; ++i) {
		std::cout << "=============== " << i <<  " ================" << std::endl;
		arr[i] = new Dog();
	}
	for (int i = 5; i < 10; i++) {
		std::cout << "=============== " << i <<  " ================" << std::endl;
		arr[i] = new Cat();
	}

	// atexit(leaks);
	
	for (int i = 0; i < 10; i++) {
		std::cout << "~~~~~~~~~~~~~~~~~~~~~ " << i <<  " ~~~~~~~~~~~~~~~~~~~~~" << std::endl;
		delete arr[i];
	}	

}