// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

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
class Solution {
public:
	static int combinationSum4(vector<int>& nums, int target);
	static string longestPalindrome(string s);
	static bool isMatch(string s, string p);
	static int longestValidParentheses(string s);
};
#endif //PCH_H
