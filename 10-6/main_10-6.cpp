#include <iostream>
#include <initializer_list>

using namespace std;

class IntArray {
private:
	int m_length = 0;
	int* m_data = nullptr;

public:
	// Constructors
	IntArray(const unsigned& length = 0) {
		initialize(length);
	}

	IntArray(const initializer_list<int>& list)
		: IntArray(static_cast<int>(list.size())) {
		int cnt = 0;
		for (auto& i : list) {
			m_data[cnt] = i;
			cnt++;
		}
	}

	IntArray(const IntArray& source) {
		copy(source);
	}

	// assignment operator overloading
	IntArray& operator =(const IntArray& source) {
		// prevent self-assignment
		if (this == &source) {
			return *this;
		}

		delete[] m_data;

		copy(source);

		return *this;
	}

	// Destructors
	~IntArray() {
		delete[] m_data;
	}

	// initialize with length
	void initialize(const unsigned& length) {
		m_length = length;
		m_data = new int[m_length];
	}

	// deep copy source
	void copy(const IntArray& source) {
		if (source.m_data != nullptr) {
			initialize(source.m_length);

			for (int i = 0; i < m_length; i++) {
				m_data[i] = source.m_data[i];
			}
		}
	}

	void reset() {
		m_length = 0;
		delete[] m_data;
		m_data = nullptr;
	}

	void resize(const int& size_in) {
		int* temp_data = new int[size_in];

		// 크기가 작아지는 경우
		if (m_length > size_in) {
			for (int i = 0; i < size_in; i++) {
				temp_data[i] = m_data[i];
			}
		}
		// 크기가 커지는 경우
		else if (m_length < size_in) {
			for (int i = 0; i < m_length; i++) {
				temp_data[i] = m_data[i];
			}
			for (int i = m_length; i < size_in; i++) {
				temp_data[i] = 0;
			}
		}

		delete[] m_data;
		m_data = temp_data;

		m_length = size_in;
	}

	void insertBefore(const int& value, const int& idx) {
		resize(m_length + 1);

		for (int i = m_length - 1; i > idx; i--) {
			m_data[i] = m_data[i - 1];
		}

		m_data[idx] = value;
	}

	void remove(const int& idx) {
		for (int i = idx + 1; i < m_length; i++) {
			m_data[i - 1] = m_data[i];
		}

		resize(m_length - 1);
	}

	void push_back(const int& value) {
		resize(m_length + 1);
		m_data[m_length - 1] = value;
	}

	int getLength() {
		return m_length;
	}

	int* getData() {
		return m_data;
	}

	// io operator overloading
	friend ostream& operator <<(ostream& out, const IntArray& intArray) {
		for (int i = 0; i < intArray.m_length; i++) {
			out << intArray.m_data[i] << ' ';
		}
		return out;
	}
};

int main() {
	/*IntArray my_arr{ 1, 3, 5, 7, 9 };

	my_arr.insertBefore(10, 1);
	cout << my_arr << endl;

	my_arr.remove(3);
	cout << my_arr << endl;

	my_arr.push_back(13);
	cout << my_arr << endl;*/

	IntArray t{ 1 };

	t.remove(0);
	cout << t << endl;

	return 0;
}