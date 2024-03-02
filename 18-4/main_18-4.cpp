#include <iostream>
#include <cctype>
#include <string>
#include <bitset>

using namespace std;

void printStates(const std::ios& stream) {
	cout << boolalpha;
	cout << "good()=" << stream.good() << endl;
	cout << "eof()=" << stream.eof() << endl;
	cout << "fail()=" << stream.fail() << endl;
	cout << "bad()=" << stream.bad() << endl;
}

int main() {

	

	return 0;
}