#include <iostream>
#include <sstream>

using namespace std;

int main() {
	stringstream os;

	//os << "12345\n67.89";
	os.str("12345\n67.89");

	string str1;
	string str2;

	os >> str1 >> str2;

	cout << str1 << " | " << str2 << endl;

	return 0;
}