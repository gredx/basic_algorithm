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

// binary_search
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


// heap
static inline int parent(int i) { return (i - 1) / 2; }

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
	// ×î´ó¶Ñ
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

template <class RandomIt>
void push_heap(RandomIt start, RandomIt limit)
{
	int len = limit - start;
	RandomIt father = start + parent(len - 1);
	RandomIt son = limit - 1;

	while (father >= start && *father < *son) {
		ly::swap(father, son);
		son = father;
		father = start + parent(son - start);
	}
}


// quick_sort
template <class RandomIt>
void quick_sort(RandomIt start, RandomIt limit)
{
	if (limit - start <= 1)return;
	int len = limit - start;
	ly::swap(start, start + rand() % len);
	auto key = *start;
	RandomIt left = start, right = limit - 1; 
	while (left < right){
		while (left < right && key < *right) right--;
		*left = *right;
		while (left < right && *left <= key) left++;
		*right = *left;
	}
	*left = key;
	quick_sort(start, left);
	quick_sort(left+1, limit);
}

// merge_sort
template <class InputIt, class OutputIt>
OutputIt copy(InputIt start, InputIt limit, OutputIt dest)
{
	while (start != limit) {
		*dest++ = *start++;
	}
	return dest;
}

// merge two sorted list into dest, and return iterator after the last element
template <class InputIt, class OutputIt>
OutputIt merge(InputIt start1, InputIt limit1, InputIt start2, InputIt limit2, OutputIt dest)
{
	for (; start1 != limit1; dest++) {
		if (start2 == limit2) 
			return ly::copy(start1, limit1, dest);
		if (*start1 < *start2) 
			*dest = *start1++;
		else 
			*dest = *start2++;
	}
	return ly::copy(start2, limit2, dest);
}

template <class RandomIt>
void merge_sort(RandomIt start, RandomIt limit)
{
	if (limit - start > 1) {
		int len = limit - start;
		auto ty = *start;
		vector<decltype(ty)> v(len);	// decltype(*start) failed. *start return Type&
		RandomIt mid = start + len / 2;

		ly::merge_sort(start, mid);
		ly::merge_sort(mid, limit);
		auto last = ly::merge(start, mid, mid, limit, v.begin());
		ly::copy(v.begin(), v.end(), start);
	}
}

class Permute {
public:
	vector<vector<int>> result;
	void permutation(vector<int>& nums, int index) {
		int len = nums.size();
		if (index == len - 1) {
			result.push_back(nums);
			return;
		}

		for (int i = index; i < len; i++) {
			std::swap(nums[i], nums[index]);
			permutation(nums, index + 1);
			std::swap(nums[i], nums[index]);
		}
	}
	// has repeat elements
	void permutation(vector<int>& nums, vector<int>& tmp, vector<int>& visit) {
		if (tmp.size() == nums.size()) {
			result.push_back(tmp);
			return;
		}
		for (int i = 0; i < nums.size(); i++) {
			if (visit[i]) continue;
			if (i > 0 && nums[i] == nums[i - 1] && visit[i - 1] == 0) continue;
			tmp.push_back(nums[i]);
			visit[i] = 1;
			permutation(nums, tmp, visit);
			visit[i] = 0;
			tmp.pop_back();
		}
	}

	vector<vector<int>> permute(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int len = nums.size();
		vector<int>visit(len,0);
		vector<int>tmp;
		permutation(nums, tmp, visit);
		return result;
	}

	// C++ algorithm next_permutation implementation
	void nextPermutation(vector<int>& nums) {
		auto start = nums.begin();
		auto limit = nums.end();
		if (limit - start <= 1) return;
		// find the first ascending pair
		auto i = limit - 1;
		while (true) {
			auto i1 = i;
			if (*--i < *i1) {
				auto i2 = limit;
				// find the first element >= *i
				while (!(*i < *--i2));	
				iter_swap(i, i2);
				reverse(i1, limit);
				return ;
			}
			if (i == start) {
				reverse(start, limit);
				return;
			}
		}
	}
};

}
