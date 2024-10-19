#include <string>
#include <iostream>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "The memory address of str : " << &str << std::endl;
	std::cout << "The memory address held by stringPTR : " << stringPTR << std::endl;
	std::cout << "The memory address held by stringREF : " << &stringREF << std::endl;

	std::cout << "The value of str : " << str << std::endl;
	std::cout << "The value pointed by : " << *stringPTR << std::endl;
	std::cout << "The value pointed by : " << stringREF << std::endl;

}