#include <iostream>
#include <exception>

using namespace std;

class A {
private:
	int m_x;

public:
	A(int x)
		: m_x(x) {
		if (x <= 0) {
			throw exception();
		}
	}
};

class B :public A {
public:
	B(int x) try
		: A(x) {}
	catch (exception& e) {
		cout << "Catch in B constructor" << endl;
		cout << e.what() << endl;
		//throw;
	}
};

int main() {
	try {
		B b(0);
	}
	catch (exception& e) {
		cout << "Catch in main()" << endl;
		cout << typeid(exception).name() << endl;
		cout << e.what() << endl;
	}

	return 0;
}