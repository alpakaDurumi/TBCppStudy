#include <iostream>

using namespace std;

class Exception {
public:
	void report() {
		cerr << "Exception report" << endl;
	}
};

class ArrayException :public Exception {
public:
	void report() {
		cerr << "Array exception" << endl;
	}
};

class MyArray {
private:
	int m_data[5];

public:
	int& operator [](const int& index) {
		if (index < 0 || 5 <= index) {
			ArrayException e;
			cout << &e << endl;
			throw e;
		}
		return m_data[index];
	}
};

void doSomething() {
	MyArray my_array;

	try {
		my_array[100];
	}
	//catch (const int& x) {
	//	cerr << "Exception " << x << endl;
	//}
	catch (Exception& e) {
		cout << "doSomething()" << endl;
		cout << &e << endl;
		e.report();
		//throw e;
		throw;
	}
	//catch (ArrayException& e) {
	//	cout << "doSomething()" << endl;
	//	e.report();
	//	//throw e;
	//}
}

int main() {
	try {
		doSomething();
	}
	//catch (ArrayException& e) {
	//	cout << "main()" << endl;
	//	e.report();
	//}
	catch (Exception& e) {
		cout << "main()" << endl;
		cout << &e << endl;
		e.report();
	}

	return 0;
}