#ifndef PCH_H
#define PCH_H

using namespace std;
#include <string>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <math.h>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <queue>

 struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int heapSortMine(vector<int>& nums, int k);
int nthUglyNumber(int n);
#endif