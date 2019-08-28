#include "pch.h"
#include "test.h"
#include "items.h"
#include "utility.h"

static void printLine()
{
	cout << endl << "**********************************************" << endl;
}
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
	printLine();
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
	printLine();
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
	printLine();

}

void test_swap()
{
	vector<int> v{ 1,2,3,4,5,6 };
	ly::swap(v.begin(), v.begin() + 3);
	for (auto x : v) {
		cout << x << " ";
	}
	printLine();
}

void test_heap()
{
	vector<double> v{ 1,2,3,4,5,6,7 };
	cout << "before make_heap" << endl;
	print_container(v.begin(), v.end());
	
	ly::make_heap(v.begin(), v.end());
	cout << "after make_heap" << endl;
	print_container(v.begin(), v.end());

	cout << "push 4 in heap" << endl;
	double val = 4;
	v.push_back(val);
	ly::push_heap(v.begin(), v.end());
	print_container(v.begin(), v.end());

	cout << "pop_heap" << endl;
	for (size_t i = v.size(); i > 0; i--) {
		cout << v[0] << " ";
		ly::pop_heap(v.begin(), v.begin() + i);
	}
	printLine();
}

void test_quick_sort()
{
	vector<double> v{ 7,6,4,48,31,4,15,8,48,78 };
	cout << "before quick_sort" << endl;
	print_container(v.begin(), v.end());

	cout << "after quick_sort" << endl;
	ly::quick_sort(v.begin(), v.end());
	print_container(v.begin(), v.end());
	printLine();
}

void test_merge()
{
	default_random_engine e;
	mt19937 mt(e());	
	uniform_int_distribution<> dis(0, 20);

	vector<int> v1(10), v2(20);
	generate(v1.begin(), v1.end(), bind(dis, ref(mt)));
	generate(v2.begin(), v2.end(), bind(dis, ref(mt)));

	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());

	cout << "v1: ";
	std::copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, " "));
	cout << '\n';

	cout << "v2: ";
	std::copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, " "));
	cout << '\n';

	vector<int> dest(30);
	ly::merge(v1.begin(), v1.end(), v2.begin(), v2.end(), dest.begin());
	cout << "dest: ";
	std::copy(dest.begin(), dest.end(), ostream_iterator<int>(cout, " "));
	printLine();
}

void test_merge_sort()
{
	default_random_engine e;
	mt19937 mt(e());
	uniform_int_distribution<> dis(0, 20);

	vector<int> v(10);
	generate(v.begin(), v.end(), bind(dis, ref(mt)));

	cout << "before sorted : ";
	std::copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
	cout << '\n';

	ly::merge_sort(v.begin(), v.end());
	cout << "after sorted: ";
	std::copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
	cout << '\n';
	printLine();
}
