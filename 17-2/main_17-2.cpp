#include <iostream>
#include <string>
#include <vector>
#include <sstream>

template<typename T>
std::string ToString(T x) {
	std::ostringstream osstream;
	osstream << x;
	return osstream.str();
}

template<typename T>
bool FromString(const std::string& str, T& x) {
	std::istringstream isstream(str);
	return (isstream >> x) ? true : false;
}

int main() {
	std::string my_str(ToString("Hello"));

	double d;
	if (FromString(my_str, d)) {
		std::cout << d << std::endl;
	}
	else {
		std::cout << "Cannot convert string to double" << std::endl;
	}


	return 0;
}