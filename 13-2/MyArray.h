#pragma once

#include <cassert>
#include <iostream>

template<typename T>
class MyArray {
private:
	int m_length;
	T* m_data;

public:
	MyArray() {
		m_length = 0;
		m_data = nullptr;
	}

	MyArray(int length) {
		m_length = length;
		m_data = new T[length];
	}

	~MyArray() {
		reset();
	}

	void reset() {
		m_length = 0;
		delete[] m_data;
		m_data = nullptr;
	}

	T& operator [](const int& index) const {
		assert(0 <= index && index < m_length);
		return m_data[index];
	}

	int getLength() {
		return m_length;
	}

	void print();
};

//template<typename T>
//void MyArray<T>::print() {
//	for (int i = 0; i < m_length; i++) {
//		std::cout << m_data[i] << ' ';
//	}
//	std::cout << std::endl;
//}
