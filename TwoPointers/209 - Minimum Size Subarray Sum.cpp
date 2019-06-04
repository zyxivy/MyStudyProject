#include "pch.h";

//same with 076
int minSubArrayLen(int s, vector<int>& a) {
	if (a.empty() == 0)
		return 0;

	int i = 0, j = 0, sum = 0, minVal = INT_MAX;

	while (j < a.size()) {
		sum += a[j++];

		while (sum >= s) {
			minVal = min(minVal, j - i);
			sum -= a[i++];
		}
	}

	return minVal == INT_MAX ? 0 : minVal;
}