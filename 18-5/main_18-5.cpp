#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main() {
	regex re("\\d+");

	string str;
	while (1) {
		getline(cin, str);

		if (std::regex_match(str, re)) {
			cout << "Match" << endl;
		}
		else {
			cout << "No match" << endl;
		}
	}

	return 0;
}