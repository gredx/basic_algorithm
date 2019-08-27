#pragma once
#include "pch.h"
namespace ly 
{
template<class RandomIt>
void swap(RandomIt left, RandomIt right) 
{
	auto tmp = *left;
	*left = *right;
	*right = tmp;
}

// 二分查找
template <class RandomIt, class T>
bool binary_search(RandomIt start, RandomIt limit, T& key)
{
	do {
		size_t len = limit - start;
		size_t index = len / 2;
		if (start[index] < key) 
			start += index + 1;
		else if (key < start[index])
			limit = start + index;
		else 
			return true;
	} while (limit - start > 0);

	return false;
}

template <class RandomIt, class T>
RandomIt lower_bound(RandomIt start, RandomIt limit, T& key)
{
	RandomIt end = limit;
	do {
		size_t len = limit - start;
		size_t index = len / 2;
		if (start[index] < key) 
			start += index + 1;
		else if (key <= start[index]) 
			limit = start + index;
	} while (limit - start > 0);
	
	if (*start == key) return start;
	else return  end;
}

template <class RandomIt, class T>
bool simple_binary_search(RandomIt start, RandomIt limit, T& key)
{
	auto pos = lower_bound(start, limit, key);
	return pos != limit;
}


// 堆
template <class RandomIt>
static void push_down(RandomIt start, RandomIt limit, size_t i)
{
	int len = limit - start;
	if (i >= len / 2) return;
	RandomIt larger = start + i;
	RandomIt leftson = start + i * 2 + 1;
	RandomIt rightson = start + i * 2 + 2;
	if (leftson < limit && *larger < *leftson) larger = leftson;
	if (rightson < limit && *larger < *rightson) larger = rightson;

	if (larger != start + i) {
		ly::swap(larger, start + i);
		push_down(start, limit, larger - start);
	}
}

template <class RandomIt>
void make_heap(RandomIt start, RandomIt limit)
{
	// 最大堆
	int len = limit - start;
	for (int i = len / 2 - 1; i >= 0; --i) {
		push_down(start, limit, i);
	}
}

template <class RandomIt>
void pop_heap(RandomIt start, RandomIt limit)
{
	ly::swap(start, --limit);
	push_down(start, limit, 0);
}

}
