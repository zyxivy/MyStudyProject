//Write a program to find the n - th ugly number.
//
//Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.
//
//Example:
//
//Input: n = 10
//Output : 12
//Explanation : 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
//Note :
//
//	1 is typically treated as an ugly number.
//	n does not exceed 1690.

#include "pch.h";
int nthUglyNumber(int n) {
    priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
    min_heap.push(make_pair(1, 1));
    int val = 0, fact = 0;
    for (int i = 0; i < n; i++) {
        auto t = min_heap.top();
        val = t.first;
        fact = t.second;
        min_heap.pop();
        // handle overflow problem
        if (fact <= 2 && val < 1073741823.5) min_heap.push(make_pair(val * 2, 2));
        if (fact <= 3 && val < 715827882.3) min_heap.push(make_pair(val * 3, 3));
        if (fact <= 5 && val < 429496729.4) min_heap.push(make_pair(val * 5, 5));
    }
    return val;
}