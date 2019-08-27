#pragma once
#include <iostream>
using namespace std;
template<class ForwardIt>
void print_container(ForwardIt start, ForwardIt limit)
{
	for (; start != limit; start++) {
		cout << *start << " ";
	}
	cout << endl;
}