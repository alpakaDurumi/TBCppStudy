#include <iostream>

using namespace std;

template<class T>
class A {
private:
	T m_value;

public:
	A(const T& input)
		: m_value(input) {}

	void print() {
		cout << m_value << endl;
	}
};

template<class T>
class A<T*> {
private:
	T* m_value;

public:
	A(T* input)
		: m_value(input) {}

	void print() {
		cout << *m_value << endl;
	}
};

int main() {
	A<int> a_int(123);
	a_int.print();

	int temp = 456;
	A<int*> a_int_ptr(&temp);
	a_int_ptr.print();

	char t = 'a';
	char* ptr1 = &t;
	const char* ptr2 = &t;

	return 0;
}