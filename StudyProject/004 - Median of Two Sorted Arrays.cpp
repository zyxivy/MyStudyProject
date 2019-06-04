#include "pch.h";
//https://leetcode.com/problems/median-of-two-sorted-arrays/discuss/2481/Share-my-O(log(min(mn))-solution-with-explanation
double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
	int m = A.size();
	int n = B.size();
	if (m > n) {
		return findMedianSortedArrays(B, A);
	}
	double ans = 0.0;
	int half = (m + n + 1) / 2;
	int low = 0;
	int high = m;
	while (low <= high) {
		int i = (low + high) / 2;
		int j = half - i;
		if (i < m && B[j - 1] > A[i]) {
			low = i + 1;
		}
		else if (i > 0 && A[i - 1] > B[j]) {
			high = i - 1;
		}
		else {
			int maxLeft = 0;
			if (i == 0) {
				maxLeft = B[j - 1];
			}
			else if (j == 0) {
				maxLeft = A[i - 1];
			}
			else {
				maxLeft = max(A[i - 1], B[j - 1]);
			}

			if ((m + n) % 2 == 1) {
				return maxLeft;
			}

			int minRight = 0;
			if (i == m) {
				minRight = B[j];
			}
			else if (j == n) {
				minRight = A[i];
			}
			else {
				minRight = min(A[i], B[j]);
			}
			ans = (maxLeft + minRight) / 2.0;
			break;
		}
	}
	return ans;
}