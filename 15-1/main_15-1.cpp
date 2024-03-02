#include <iostream>
#include "Resource.h"
#include "AutoPtr.h"

using namespace std;

void doSomething() {
	try {
		//Resource* res = new Resource;	// dull pointer
		AutoPtr<Resource> res(new Resource);	// smart pointer

		// work with res

		if (1) {
			throw - 1;
		}

		//delete res;
	}
	catch (...) {

	}

	return;
}

int main() {
	//doSomething();

	{
		AutoPtr<Resource> res1 = new Resource;
		//AutoPtr<Resource> res1(new Resource);
		AutoPtr<Resource> res2;

		cout << std::boolalpha;

		cout << res1.m_ptr << endl;
		cout << res2.m_ptr << endl;

		res2 = res1;

		cout << res1.m_ptr << endl;
		cout << res2.m_ptr << endl;
	}

	return 0;
}