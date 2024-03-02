#include <iostream>
#include <array>
//#include "Storage8.h"

using namespace std;

template<typename T>
class A {
public:
	A(const T& input) {}

	void doSomething() {
		cout << typeid(T).name() << endl;
	}

	void test() {}
};

template<>
class A<char> {
public:
	A(const char& temp) {}

	void doSomething() {
		cout << "Char type specialization" << endl;
	}
};

int main() {
	A a_int(1);
	A a_double(3.14);
	A a_char('a');

	a_int.doSomething();
	a_double.doSomething();
	a_char.doSomething();

	return 0;
}