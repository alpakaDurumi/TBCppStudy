#include <iostream>
#include <string>

using namespace std;

class Animal {
protected:
	string m_name;

public:
	Animal(string name)
		: m_name(name) {
	}

	string getName() {
		return m_name;
	}

	void speak() const {
		cout << m_name << " ???" << endl;
	}
};

class Cat :public Animal {
public:
	Cat(string name)
		: Animal(name) {
	}

	void speak() const {
		cout << m_name << " Meow" << endl;
	}
};

class Dog :public Animal {
public:
	Dog(string name)
		: Animal(name) {
	}

	void speak() const {
		cout << m_name << " Woof" << endl;
	}
};

int main() {
	//Animal animal("my animal");
	//Cat cat("my cat");
	//Dog dog("my dog");

	//Animal* ptr_animal1 = &cat;
	//Animal* ptr_animal2 = &dog;

	//ptr_animal1->speak();
	//ptr_animal2->speak();

	//

	Cat cats[]{ Cat("cat1"), Cat("cat2"), Cat("cat3") , Cat("cat4") , Cat("cat5") };
	Dog dogs[]{ Dog("dog1"), Dog("dog2") };

	Animal* my_animals[] = { &cats[0], &cats[1], &cats[2] ,&cats[3], &cats[4], &dogs[0], &dogs[1] };

	cout << "abcd" << endl;

	for (int i = 0; i < 7; i++) {
		my_animals[i]->speak();
	}

	//Animal my_animals[]{Cat("cat0")}



	return 0;
}