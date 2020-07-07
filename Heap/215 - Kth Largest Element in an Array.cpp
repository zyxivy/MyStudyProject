//Find the kth largest element in an unsorted array.Note that it is the kth largest element in the sorted order, not the kth distinct element.
//
//Example 1:
//
//Input: [3, 2, 1, 5, 6, 4] and k = 2
//Output : 5
//Example 2 :
//
//	Input : [3, 2, 3, 1, 2, 4, 5, 5, 6] and k = 4
//	Output : 4
//	Note :
//	You may assume k is always valid, 1 ≤ k ≤ array's length.

#include "pch.h";
void heapify(vector<int>& nums, int end, int i) {
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < end && nums[i] < nums[left]) {
		largest = left;
	}
	if (right < end && nums[largest] < nums[right]) {
		largest = right;
	}

	if (largest != i) {
		swap(nums[largest], nums[i]);
		heapify(nums, end, largest);
	}
}

int heapSortMine(vector<int>& nums, int k) {
	int n = nums.size();

	for (int i = n / 2 - 1; i >= 0; i--) {
		heapify(nums, n, i);
	}

	for (int i = n - 1; i >= 0; i--, k--) {
		swap(nums[0], nums[i]);
		if (k == 0) {
			return nums[i];
		}
		heapify(nums, i, 0);
	}
}

int findKthLargest(vector<int>& nums, int k) {
	return heapSortMine(nums, k);
}