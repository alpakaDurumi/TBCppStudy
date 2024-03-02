#include <iostream>

using namespace std;

class Base {
protected:
	int m_i;

public:
	Base(int value)
		: m_i(value) {
	}

	void print() {
		cout << "I'm base" << endl;
	}
};

class Derived :public Base {
public:
	Derived(int value)
		: Base(value) {
	}

	using Base::m_i;

private:
	using Base::print;	// do not add ()
	void print() = delete;
};

int main() {
	Derived derived(7);
	derived.m_i = 1024;
	//derived.print();

	return 0;
}