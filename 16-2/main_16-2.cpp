#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>

using namespace std;

int main() {
	map<int, char> container;
	for (int i = 0; i < 10; i++) {
		container.insert(make_pair(i, i + 65));
	}

	for (auto itr = container.begin(); itr != container.end(); itr++) {
		cout << itr->first << ' ' << itr->second << endl;
	}

	return 0;
}