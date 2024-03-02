#include "MyArray.h"

int main() {
	MyArray<double, 100> my_array;

	for (int i = 0; i < my_array.getLength(); i++) {
		my_array[i] = i;
	}

	my_array.print();

	return 0;
}