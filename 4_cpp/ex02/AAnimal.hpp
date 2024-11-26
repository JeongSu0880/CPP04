#ifndef AANIMAL_HPP
# define AANIMAL_HPP
# include <iostream>

class AAnimal {
protected:
	std::string type;
public:
	AAnimal();
	AAnimal(const std::string &name);
	AAnimal(const AAnimal &original);
	virtual ~AAnimal();

	AAnimal &operator=(const AAnimal &original);

	virtual void makeSound() const = 0;

	std::string getType() const;
};

#endif

// 가가상하ㅣㅁ수를 사용하는 이유 중 하나 -> 함함수에 대한 구현이 다 다른 클래스들이 존재할 수 있다는 것 . 이  과제는 그에 해당하는 예시를 보여주기 위한 과제
//과제의 의도 -> 가상함수를 사용해보고, 이이를 상속받는 클래스에서 오버 라이딩을 해보아라. 
// virtual ㅋㅣ우ㅓ드가 소멸자에 붙는 이유 -> 붙지 않으면 동적 바인딩을 하게 되는데, 만일... 부모 클래스 변수에 자식 클래스 객체가 선언되었을 때 
// 동적 바인딩은 변수에 데이터 타입에 따라 소멸자를 호출하므로 이런 경우 부모 클래스의 소멸자가 바로 호출이 되어서 자식 클래스는 누수가 된다.  (업케스팅이 된 경우)