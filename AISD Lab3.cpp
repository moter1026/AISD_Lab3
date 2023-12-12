// AISD Lab3.cpp: определяет точку входа для приложения.
//

#include "AISD Lab3.h"

using namespace std;

int main()
{
	{
		vector<int> vec;
		vec.push_back(2);
		vec.push_back(5);
		vec.push_back(3);
		vec.push_back(7);
		vec.push_back(9);
		vec.push_back(50);
		vec.push_back(1);
		vec.push_back(2);
		vec.push_back(34);
		cout << "1. InsertSort =";
		for (auto& v : vec) {
			cout << " " << v;
		}
		cout << endl;
		Stats stats = InsertSort(vec);
		cout << "2. InsertSort =";
		for (auto& v : vec) {
			cout << " " << v;
		}
		cout << endl;
		cout << "comparison_count: " << stats.comparison_count << endl;
		cout << "copy_count: " << stats.copy_count << endl;
	}
	cout << endl;
	cout << endl;
	{
		vector<int> vec;
		vec.push_back(2);
		vec.push_back(5);
		vec.push_back(3);
		vec.push_back(7);
		vec.push_back(9);
		vec.push_back(50);
		vec.push_back(1);
		vec.push_back(2);
		vec.push_back(34);
		cout << "1. ShakerSort =";
		for (auto& v : vec) {
			cout << " " << v;
		}
		cout << endl;
		Stats stats = ShakerSort(vec);
		cout << "2. ShakerSort =";
		for (auto& v : vec) {
			cout << " " << v;
		}
		cout << endl;
		cout << "comparison_count: " << stats.comparison_count << endl;
		cout << "copy_count: " << stats.copy_count << endl;
	}
	cout << endl;
	cout << endl;
	{
		vector<int> vec;
		vec.push_back(2);
		vec.push_back(5);
		vec.push_back(3);
		vec.push_back(7);
		vec.push_back(9);
		vec.push_back(50);
		vec.push_back(1);
		vec.push_back(2);
		vec.push_back(34);
		cout << "1. HeapSort =";
		for (auto& v : vec) {
			cout << " " << v;
		}
		cout << endl;
		Stats stats = HeapSort(vec);
		cout << "2. HeapSort =";
		for (auto& v : vec) {
			cout << " " << v;
		}
		cout << endl;
		cout << "comparison_count: " << stats.comparison_count << endl;
		cout << "copy_count: " << stats.copy_count << endl;
	}
	return 0;
}
