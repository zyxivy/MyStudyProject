#include "pch.h";

vector<int> twoSum(vector<int>& numbers, int target) {
	vector<int> ans(2, 0);
	if (numbers.size() < 2) {
		return ans;
	}

	int left = 0;
	int right = numbers.size() - 1;

	while (left<right) {
		if (numbers[left] + numbers[right] < target) {
			left++;
		}
		else if (numbers[left] + numbers[right] > target) {
			right--;
		}
		else {
			break;
		}
	}
	ans[0] = left + 1;
	ans[1] = right + 1;
	return ans;
}