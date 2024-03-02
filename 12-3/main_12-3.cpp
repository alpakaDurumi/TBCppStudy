#include <iostream>

using namespace std;

class A {
public:
	void print() {
		cout << "A" << endl;
	}

	virtual A* getThis() {
		return this;
	}
};

class B : public A {
public:
	void print() {
		cout << "B" << endl;
	}

	virtual B* getThis() {
		return this;
	}
};

class C : public B {
public:
	virtual void print() {
		cout << "C" << endl;
	}
};

int main() {
	A a;
	B b;
	//C c;
	//D d;

	A& ref = b;
	b.getThis()->print();
	ref.getThis()->print();

	cout << typeid(b.getThis()).name() << endl;
	cout << typeid(ref.getThis()).name() << endl;

	return 0;
}