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
	static vector<string> letterCombinations(string digits);
	static vector<string> generateParenthesis(int n);
	static void solveSudoku(vector<vector<char>>& board);
	static vector<vector<int>> combinationSum(vector<int>& candidates, int target);
	static vector<vector<int>> combinationSumII(vector<int>& candidates, int target);
	static vector<vector<int>> combinationSum3(int k, int n);
	static vector<vector<int>> permute(vector<int>& nums);
	static vector<vector<int>> permuteUnique(vector<int>& nums);
	static string getPermutation(int n, int k);
	static vector<vector<string>> solveNQueens(int n);
	static int totalNQueens(int n);
	static vector<vector<int>> subsetsWithDup(vector<int>& nums);
	static vector<vector<int>> subsets(vector<int>& nums);
	static bool exist(vector<vector<char>>& board, string word);
	static vector<string> findWords(vector<vector<char>>& board, vector<string>& words);
};
#endif //PCH_H