#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	string my_str("abcdefg");

	char buf[20];

	my_str.copy(buf, 5, 0);

	buf[5] = '\0';

	cout << buf << endl;

	my_str.copy(buf, 5, 1);

	cout << buf << endl;

	return 0;
}