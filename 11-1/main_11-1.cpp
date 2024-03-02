#include <iostream>

using namespace std;

class Mother {
public:
	int m_i;

public:
	Mother(const int& i_in)
	: m_i(i_in) {

	}

	void setValue(const int& i_in) {
		m_i = i_in;
	}

	int getValue() {
		return m_i;
	}
};

class Child :public Mother {
private:
	double m_d;

public:
	Child(const int& i_in = 0, const double& d_in = 0.0)
		: Mother(i_in), m_d(d_in) {
	}

	void setValue(const int& i_in, const double& d_in) {
		Mother::setValue(i_in);
		m_d = d_in;
	}

	void setValue(const double& d_in) {
		m_d = d_in;
	}

	double getValue() {
		return m_d;
	}
};

int main() {
	Mother mother(512);
	cout << mother.getValue() << endl;

	Child child(1024, 128);
	child.Mother::setValue(128);
	cout << child.getValue() << endl;

	return 0;
}