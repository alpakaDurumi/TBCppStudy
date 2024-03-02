#include <iostream>

using namespace std;

void last() throw(int) {
	cout << "last" << endl;
	cout << "Throws exception" << endl;
	throw - 1;
	cout << "End last" << endl;
}

void third() {
	cout << "third" << endl;

	last();

	cout << "End third" << endl;
}

void second() {
	cout << "Second" << endl;

	try {
		third();
	}
	catch (double) {
		cerr << "Second caught double exception" << endl;
	}
	cout << "End second" << endl;
}

void first() {
	cout << "first" << endl;

	try {
		second();
	}
	catch (int) {
		cerr << "first caught int exception" << endl;
	}
	cout << "End first" << endl;
}

int main() {
	cout << "Start" << endl;

	try {
		first();
	}
	catch (int) {
		cerr << "main caught int exception" << endl;
	}
	catch (...) {
		cerr << "main caught ellipses exception" << endl;
	}

	return 0;
}