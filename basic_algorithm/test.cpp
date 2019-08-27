#include "pch.h"
#include "test.h"
#include "items.h"
#include "utility.h"
void test_binary_search()
{
	vector<double> v{ 1, 2, 3, 4, 5, 6, 7, 8 };
	vector<double> test{ 4, 5, 5.5 };
	for (auto key : test) {
		bool flag = ly::binary_search(v.begin(), v.end(), key);
		if (flag) {
			cout << key << " is found" << endl;
		}
		else {
			cout << key << " not exist" << endl;
		}
	}
	cout << "***************************************" << endl;

}

void test_lower_bound()
{
	vector<double> v{ 1, 2, 3, 4, 4, 5, 5, 5, 6, 7 };
	vector<double> test{ 2,4,5,5.5 };

	for (auto key : test) {
		auto pos = ly::lower_bound(v.begin(), v.end(), key);
		if (pos != v.end())
			cout << key << " in pos " << pos - v.begin() << endl;
		else cout << key << " no exist" << endl;
	}
	cout << "***************************************" << endl;
}

void test_simple_binary_search()
{
	vector<double> v{ 1, 2, 3, 4, 5, 6, 7, 8 };
	vector<double> test{ 4, 5, 5.5 };
	for (auto key : test) {
		bool flag = ly::simple_binary_search(v.begin(), v.end(), key);
		if (flag) {
			cout << key << " is found" << endl;
		}
		else {
			cout << key << " not exist" << endl;
		}
	}
	cout << "***************************************" << endl;

}

void test_swap()
{
	vector<int> v{ 1,2,3,4,5,6 };
	ly::swap(v.begin(), v.begin() + 3);
	for (auto x : v) {
		cout << x << " ";
	}cout << endl << "*********************************" << endl;
}

void test_heap()
{
	vector<double> v{ 1,2,3,4,5,6,7 };
	cout << "before make_heap" << endl;
	print_container(v.begin(), v.end());
	
	ly::make_heap(v.begin(), v.end());
	cout << "after make_heap" << endl;
	print_container(v.begin(), v.end());

	cout << "pop_heap" << endl;
	for (size_t i = v.size(); i > 0; i--) {
		cout << v[0] << " ";
		ly::pop_heap(v.begin(), v.begin() + i);
	}
	cout << endl << "*********************************" << endl;
}
