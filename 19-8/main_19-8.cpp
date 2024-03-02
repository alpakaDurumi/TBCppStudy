#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct S {
	int m_x;

	S() {
		m_x = 42;
	}
};

const S foo() {
	return S();
}

const int& foobar() {
	return 123;
}

//template<typename T, typename S>
//auto fpmin_wrong(T x, S y) -> decltype(x < y ? x : y){
//	return x < y ? x : y;
//}
//
//template<typename T, typename S>
//auto fpmin(T x, S y) -> typename std::remove_reference<decltype(x < y ? x : y)>::type {
//	return x < y ? x : y;
//}

template<typename R>
class SomeFunctor {
public:
	typedef R result_type;

	SomeFunctor() {}

	result_type operator() () {
		return R();
	}
};

int main() {
	// generic lambda
	auto lambda = [](auto x, auto y) {
		return x + y;
		};

	cout << lambda(1.1, 2) << ' ' << lambda(3, 4) << ' ' << lambda(4.5, 2.2) << endl;


	return 0;
}