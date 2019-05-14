#include "pch.h";

/*
https://en.wikipedia.org/wiki/Permutation#Generation_in_lexicographic_order
Find the largest index k such that a[k] < a[k + 1]. If no such index exists, the permutation is the last permutation.
2.Find the largest index l greater than k such that a[k] < a[l].
3.Swap a[k] and a[l].
4.Reverse the sequence from a[k + 1] up to and including the final element a[n].
*/
void Solution::nextPermutation(vector<int>& nums) {
	if (nums.size() < 2) {
		return;
	}
	int k = nums.size() - 2;
	while(k >= 0){
		if (nums[k] < nums[k + 1]) 
			break;
		
		k--;
	}
	if (k != -1) {
		int l = nums.size() - 1;
		while(l > k) {
			if (nums[l] > nums[k])
				break;

			l--;
		}

		swap(nums[k], nums[l]);
	}
	int i = k + 1;
	int j = nums.size() - 1;
	while (i < j) {
		swap(nums[i], nums[j]);
		i++;
		j--;
	}
}