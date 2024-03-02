#include <iostream>
#include <string>

using namespace std;

int main() {
	string str1("one");
	string str2("two");

	str1 = str1 + " ";

	str1 += str2 + " three";

	str1.push_back('A');

	cout << str1 << endl;

	return 0;
}