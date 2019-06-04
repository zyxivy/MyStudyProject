#include "pch.h";

int hIndex(vector<int>& citations) {
	if (citations.empty()) {
		return 0;
	}
	int len = citations.size();

	vector<int> bucket(len + 1, 0);
	for (int n : citations) {
		if (n >= len) {
			bucket[len]++;
		}
		else {
			bucket[n]++;
		}
	}

	int count = 0;
	for (int i = len; i >= 0; i--) {
		count += bucket[i];
		if (count >= i) {
			return i;
		}
	}
	return 0;
}