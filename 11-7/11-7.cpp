#include <iostream>

using namespace std;

class Base {
protected:
	int m_value;

public:
	Base(int value)
		: m_value(value) {
	}

	void print() {
		cout << "I'm base" << endl;
	}

	friend ostream& operator <<(ostream& out, const Base& base) {
		out << "This is base output";
		return out;
	}
};

class Derived :public Base {
public:
	Derived(int value)
		: Base(value) {
	}

	void print() {
		Base::print();
		cout << "I'm derived" << endl;
	}

	friend ostream& operator <<(ostream& out, const Derived& derived) {
		out << static_cast<Base>(derived) << endl;
		out << "This is derived output";
		return out;
	}
};

int main() {

	Base base(5);
	cout << base << endl;
	// This is base output

	Derived derived(7);
	cout << derived << endl;
	// This is base output
	// This is derived output

	return 0;
}