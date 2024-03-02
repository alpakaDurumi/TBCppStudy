#include <iostream>
#include "MyArray.h"

int main() {
	MyArray<char> my_array(10);

	for (int i = 0; i < my_array.getLength(); i++) {
		my_array[i] = i + 97;
	}

	my_array.print();

	return 0;
}