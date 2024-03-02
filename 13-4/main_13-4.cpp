#include <iostream>
#include "Storage.h"

using namespace std;

template<>
void Storage<double>::print() {
	std::cout << "Double Type ";
	std::cout << std::scientific << m_value << '\n';
}

//template<typename T>
//T getMax(T x, T y) {
//	return (x > y) ? x : y;
//}
//
//template<>
//char getMax(char x, char y) {
//	cout << "Warning : comparing chars" << endl;
//	return (x > y) ? x : y;
//}

int main() {
	Storage<int> nValue(5);
	Storage<double> dValue(6.7);

	nValue.print();
	dValue.print();

	return 0;
}