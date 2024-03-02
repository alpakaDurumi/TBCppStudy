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

	virtual void speak() const = 0;		// pure virtual function
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

class Cow :public Animal {
public:
	Cow(string name)
		: Animal(name) {};

	void speak() const override {
		cout << m_name << " Moooo" << endl;
	}
};

int main() {
	Cow cow("cow");
	cow.speak();

	return 0;
}