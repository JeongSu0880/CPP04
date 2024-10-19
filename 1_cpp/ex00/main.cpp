#include "Zombie.hpp"

// void leaks()
// {
// 	system("leaks ex00");
// }

int main()
{
	// atexit(leaks);
	Zombie zombie1 = Zombie("zombie1");
	Zombie *zombie2 = new Zombie("zombie2");

	zombie1.announce();
	zombie2->announce();

	Zombie *zombie3 = zombie1.newZombie("zombie3");
	zombie3->announce();
	zombie1.randomChump("zombie4");
	// zombie4.announc(); 는 안된다!

	delete zombie2;
	delete zombie3;// 이거 주석하고 atexit 확인해보면...
}