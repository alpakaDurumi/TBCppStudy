#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
	char buf1[5];
	char buf2[5];

	cin.getline(buf1, 5);
	cin.getline(buf2, 5);

	cout << buf1 << endl;
	cout << buf2 << endl;

	return 0;
}