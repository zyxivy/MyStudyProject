#include "pch.h";

//Put each number in its right place.
//For example :
//When we find 5, then swap it with A[4].
//At last, the first place where its number is not right, return the place + 1.
int firstMissingPositive(vector<int>& A) {
	int n = A.size();
	int i = 0;
	while (i < n) {
		if (A[i] > 0 && A[i] <= n && A[A[i] - 1] != A[i])
			swap(A[i], A[A[i] - 1]);
		else i++;
	}
	for (int i = 0; i < n; i++) {
		if (A[i] != i + 1) {
			return i + 1;
		}
	}
	return n + 1;
}