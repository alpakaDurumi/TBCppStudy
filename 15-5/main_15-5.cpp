#include <iostream>
#include <memory>
#include "Resource.h"

#include <iomanip>

using namespace std;

//void doSomething2(std::unique_ptr<Resource>& res) {
//auto doSomething2(std::unique_ptr<Resource> res) {
void doSomething2(Resource* res) {
	res->setAll(10);
	//return res;
}

int main() {
	//{
	//	std::unique_ptr<Resource> res(new Resource(10000000));
	//}

	//{
	//	std::unique_ptr<int> upi(new int);

	//	//unique_ptr<Resource> res1(ptr);
	//	auto res1 = std::make_unique<Resource>(5);

	//	res1->setAll(5);
	//	res1->print();

	//	std::unique_ptr<Resource> res2;

	//	cout << boolalpha;
	//	cout << static_cast<bool>(res1) << endl;
	//	cout << static_cast<bool>(res2) << endl;

	//	res2 = std::move(res1);

	//	cout << static_cast<bool>(res1) << endl;
	//	cout << static_cast<bool>(res2) << endl;

	//	if (res1 != nullptr) res1->print();
	//	if (res2 != nullptr) res2->print();
	//}

	{
		auto res1 = std::make_unique<Resource>(5);
		res1->setAll(1);
		res1->print();

		//doSomething2(res1);
		//res1 = doSomething2(std::move(res1));
		doSomething2(res1.get());

		res1->print();
	}

	{
		Resource* res = new Resource;
		std::unique_ptr<Resource> res1(res);
		std::unique_ptr<Resource> res2(res);

		delete res;
	}

	return 0;
}