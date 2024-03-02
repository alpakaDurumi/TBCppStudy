#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

//int findFirstChar(const char* string, char ch) {
//	for (size_t index = 0; index < strlen(string); index++) {
//		if (string[index] == ch) {
//			return index;
//		}
//	}
//	return -1;	// no match
//}
//
//double divide(int x, int y, bool& success) {
//	if (y == 0) {
//		success = false;
//		return 0.0;
//	}
//
//	success = false;
//}

int main() {
	// try, catch, throw

	try {
		throw string("abc");
	}
	catch (int x) {
		cout << "Catch integer " << x << endl;
	}
	catch (double x) {
		cout << "Catch double " << x << endl;
	}
	catch (char* error_message) {
		cout << "Catch char* " << error_message << endl;
	}
	catch (string error_message) {
		// do something to respond
		cout << error_message << endl;
	}


	return 0;
}