#include "search.h"

// binary search - log2(N) complexity :
int vec_binary_search (int vec[], int target, int size) {
	return vec_binary_search_region (vec, target, 0, size - 1);
}
int vec_binary_search_region (int vec[], int target, int start, int end) {
	int mid = (end + start) / 2;
	if (start > end)
		return -1;
	if (target > vec [mid])
		return vec_binary_search_region (vec, target, mid + 1, end);
	else if (target < vec [mid])
		return vec_binary_search_region (vec, target, start, mid - 1);
	return mid;
}
