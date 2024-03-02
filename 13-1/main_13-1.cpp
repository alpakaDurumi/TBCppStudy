#include <iostream>

using namespace std;

template<typename T>
T getMax(T x, T y) {
	return (x > y) ? x : y;
}

int main() {
	cout << getMax(1, 2) << endl;

	return 0;
}