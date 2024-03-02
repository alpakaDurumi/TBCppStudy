#include <iostream>

using namespace std;

class Base {
public:
	int m_public;
protected:
	int m_protected;
private:
	int m_private;
};

class Derived :protected Base {
public:
	Derived() {
		m_public = 123;
		m_protected = 123;
	}
};

class GrandChild :public Derived {
public:
	Derived::m_public;
	Derived::m_protected;
	//Derived::m_private;
};

int main() {
	Base base;

	Derived d;


	return 0;
}