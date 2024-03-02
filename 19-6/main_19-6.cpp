#include <iostream>
#include <chrono>
#include <mutex>
#include <random>
#include <thread>
#include <utility>
#include <atomic>
#include <future>
#include <numeric>
#include <execution>
#include <vector>

using namespace std;

mutex mtx;

auto dotProductFuture(const vector<int>& v0, const vector<int>& v1, const unsigned i_start, const unsigned i_end) {
	int sum = 0;
	for (unsigned i = i_start; i < i_end; i++) {
		sum += v0[i] * v1[i];
	}

	return sum;
}

auto dotProductThread(const vector<int>& v0, const vector<int>& v1, const unsigned i_start, const unsigned i_end, unsigned& local_sum) {
	unsigned t = 0;
	for (unsigned i = i_start; i < i_end; i++) {
		t += v0[i] * v1[i];
	}
	local_sum = t;
}

thread_local unsigned local_sum = 0;

auto dotProductThreadLocal(const vector<int>& v0, const vector<int>& v1, const unsigned i_start, const unsigned i_end, unsigned long long& sum) {
	for (unsigned i = i_start; i < i_end; i++) {
		local_sum += v0[i] * v1[i];
	}
	sum += local_sum;
}

auto dotProductPromise(const vector<int>& v0, const vector<int>& v1, const unsigned i_start, const unsigned i_end, std::promise<int>&& prom) {
	int sum = 0;
	for (unsigned i = i_start; i < i_end; i++) {
		sum += v0[i] * v1[i];
	}
	prom.set_value(sum);
}

int main() {
	const long long n_data = 100'000'000;
	const unsigned n_threads = 4;

	std::vector<int> v0, v1;
	v0.reserve(n_data);
	v1.reserve(n_data);

	random_device seed;
	mt19937_64 engine(seed());

	uniform_int_distribution<> uniformDist(1, 10);

	for (long long i = 0; i < n_data; i++) {
		v0.push_back(uniformDist(engine));
		v1.push_back(uniformDist(engine));
	}

	cout << "std::inner_product" << endl;
	{
		const auto sta = chrono::steady_clock::now();

		const auto sum = std::inner_product(v0.begin(), v0.end(), v1.begin(), 0ull);

		const chrono::duration<double> dur = chrono::steady_clock::now() - sta;

		cout << dur.count() << endl;
		cout << sum << endl;
		cout << endl;
	}

	cout << "Future" << endl;
	{
		const auto sta = chrono::steady_clock::now();

		unsigned long long sum = 0;

		vector<std::future<int>> futures;
		futures.resize(n_threads);

		const unsigned n_per_thread = n_data / n_threads;
		for (unsigned t = 0; t < n_threads; t++) {
			futures[t] = std::async(dotProductFuture, std::ref(v0), std::ref(v1), t * n_per_thread, (t + 1) * n_per_thread);
		}

		for (unsigned t = 0; t < n_threads; t++) {
			sum += futures[t].get();
		}

		const chrono::duration<double> dur = chrono::steady_clock::now() - sta;

		cout << dur.count() << endl;
		cout << sum << endl;
		cout << endl;
	}

	// TODO #1 : use divide and conquer strategy for std::thread
	cout << "thread" << endl;
	{
		const auto sta = chrono::steady_clock::now();

		unsigned long long sum = 0;

		vector<std::thread> threads;
		vector<unsigned> sums;
		threads.resize(n_threads);
		sums.resize(n_threads);

		const unsigned n_per_thread = n_data / n_threads;
		for (unsigned t = 0; t < n_threads; t++) {
			
			threads[t] = std::thread(dotProductThread, std::ref(v0), std::ref(v1), t * n_per_thread, (t + 1) * n_per_thread, std::ref(sums[t]));
		}

		for (unsigned t = 0; t < n_threads; t++) {
			threads[t].join();
			sum += sums[t];
			cout << sums[t] << ' ';
		}

		const chrono::duration<double> dur = chrono::steady_clock::now() - sta;

		cout << dur.count() << endl;
		cout << sum << endl;
		cout << endl;
	}

	cout << "-------------------" << endl;

	// thread_local
	cout << "thread_local" << endl;
	{
		const auto sta = chrono::steady_clock::now();

		unsigned long long sum = 0;

		vector<std::thread> threads;
		threads.resize(n_threads);

		const unsigned n_per_thread = n_data / n_threads;
		for (unsigned t = 0; t < n_threads; t++) {
			threads[t] = std::thread(dotProductThreadLocal, std::ref(v0), std::ref(v1), t * n_per_thread, (t + 1) * n_per_thread, std::ref(sum));
		}

		for (unsigned t = 0; t < n_threads; t++) {
			threads[t].join();
		}

		const chrono::duration<double> dur = chrono::steady_clock::now() - sta;

		cout << dur.count() << endl;
		cout << sum << endl;
		cout << endl;
	}

	// TODO #2 : use divide and conquer strategy for std::atomic
	
	//// TODO #3 : use divide and conquer strategy for std::thread with std::promise
	//cout << "thread and promise" << endl;
	//{
	//	const auto sta = chrono::steady_clock::now();

	//	unsigned long long sum = 0;

	//	vector<std::promise<int>> promises;
	//	vector<std::future<int>> futures;
	//	vector<std::thread> threads;
	//	promises.resize(n_threads);
	//	futures.resize(n_threads);
	//	threads.resize(n_threads);

	//	const unsigned n_per_thread = n_data / n_threads;
	//	for (unsigned t = 0; t < n_threads; t++) {
	//		futures[t] = promises[t].get_future();
	//		threads[t] = std::thread(dotProductPromise, std::ref(v0), std::ref(v1), t * n_per_thread, (t + 1) * n_per_thread, std::move(promises[t]));
	//	}

	//	for (unsigned t = 0; t < n_threads; t++) {
	//		sum += futures[t].get();
	//		threads[t].join();
	//	}

	//	const chrono::duration<double> dur = chrono::steady_clock::now() - sta;

	//	cout << dur.count() << endl;
	//	cout << sum << endl;
	//	cout << endl;
	//}
	// TODO #2 : use promise

	return 0;
}