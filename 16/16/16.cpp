#include <iostream>       // std::cout
#include <thread>         // std::thread
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <atomic>
#include <mutex>
#include <vector>

using namespace std;

std::mutex mt;

bool d = 0;

void del(unsigned long long begin, unsigned long long end, unsigned long long a)
{
	unique_lock<std::mutex> lock(mt, defer_lock);

	for (unsigned long long i = begin; i < end; i++)
	{
		if (!(a%i)) d = 1;
	}
}

int main()
{
	unsigned long long a;
	cout << "Enter the number: ";
	cin >> a;
	int th;
	cout << "Enter the number of threads: ";
	cin >> th;
	unsigned long long b = (a / 2) / th;
	vector<thread> v;
	unsigned long long begin = 2;

	auto start_time = chrono::system_clock::now();
	for (int i = 0; i < th; i++)
	{
		v.push_back(thread(del, begin, begin + b, a));
		begin += b;
	}

	for (int j = 0; j < th; j++)
	{
		v[j].join();
	}

	if (!d) cout << "Yes" << endl;
	else cout << "No" << endl;

	auto end_time = chrono::system_clock::now();
	auto dif = end_time - start_time;
	cout << chrono::duration_cast<chrono::milliseconds>(dif).count() << endl;

	system("pause");
	return 0;
}