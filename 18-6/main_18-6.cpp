#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream>

using namespace std;

int main() {
	if (1) {
		ofstream ofs("my_first_file.dat");

		//ofstream ofs;
		// ofs.open("my_first_file.dat");

		if (!ofs) {
			cerr << "couldn't open file" << endl;
			exit(1);
		}

		const unsigned num_data = 10;					// 데이터의 개수
		ofs.write((char*)&num_data, sizeof(num_data));	// s

		for (int i = 0; i < num_data; i++) {
			ofs.write((char*)&i, sizeof(i));
		}


		//ofs << "Line 1" << endl;
		//ofs << "Line 2" << endl;
	}

	if (1) {
		//ifstream ifs("my_first_file.dat", ios::binary);
		ifstream ifs("my_first_file.dat");

		if (!ifs) {
			cerr << "Cannot open file" << endl;
			exit(1);
		}

		//while (ifs) {
		//	std::string str;
		//	getline(ifs, str);

		//	std::cout << str << endl;
		//}

		unsigned num_data = 0;
		ifs.read((char*)&num_data, sizeof(num_data));

		for (unsigned i = 0; i < num_data; i++) {
			int num;
			ifs.read((char*)&num, sizeof(num));

			std::cout << num << endl;
		}
	}

	return 0;
}