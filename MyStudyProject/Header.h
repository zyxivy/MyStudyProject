#pragma once

using namespace std;
#include <string>
#include <vector>
#include <set>
#include <map>
//#include <math.h>
#include <iostream>
#include <unordered_set>

struct ListNode
{
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct TreeLinkNode {
    TreeLinkNode *left;
    TreeLinkNode *right;
    TreeLinkNode *next;
};

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};    
};

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 };
class LRUCache {
public:
    LRUCache(int capacity);
    int get(int key); 
    void put(int key, int value);
private:
    int m_capacity;
    struct CacheEntry {
        int key;
        int val;
        CacheEntry(int x, int y) : key(x), val(y) {}
    };
    vector<CacheEntry> queue;
    map<int, vector<CacheEntry>::iterator> mp;
};

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};
class Solution {
    // 001
public:
    static vector<int> twoSum(vector<int>& nums, int target);
    //002
public:
    static ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
    //003
public:
    static int lengthOfLongestSubstring(string s);
    //004
public:
    static double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);
    //005
public:
    static string longestPalindrome(string s);
    //006
public:
    static string ZigZagConvert(string s, int numRows);
    //007
public:
    static int reverseInteger(int x);
    //008
public:
    static int myAtoi(string str);
    //009
public:
    static bool isPalindrome(int x);
    //010
public:
    static bool isMatch(string s, string p);
    //011
public:
    static int maxArea(vector<int>& height);
    //012
public:
    static string intToRoman(int num);
    //013
public:
    static int romanToInt(string s);
    //014
public:
    static string longestCommonPrefix(vector<string>& strs);
    //015
public:
    static vector<vector<int>> threeSum(vector<int>& nums);
    //017
public:
    static vector<string> letterCombinations(string digits);
    //019
public:
    static ListNode* removeNthFromEnd(ListNode* head, int n);
    //020
public:
    static bool isValidParentheses(string s);
    //021
public:
    static ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);
    //022
public:
    static vector<string> generateParenthesis(int n);
    //023
public:
    static ListNode* mergeKLists(vector<ListNode*>& lists);
	//024
public:
	static ListNode* swapPairs(ListNode* head);
	//025
public:
	static ListNode* reverseKGroup(ListNode* head, int k);
	//026
public:
	static int removeDuplicates(vector<int>& nums);
	//027
public:
	static int removeElement(vector<int>& nums, int val);
	//028
public:
	static int strStr(string haystack, string needle);
    //029
public:
    static int divide(int dividend, int divisor);
    //030
public:
    static vector<int> findSubstring(string s, vector<string>& words);
    //031
public:
    static void nextPermutation(vector<int>& nums);
    //032
public:
    static int longestValidParentheses(string s);
    //033
public:
    static int search(vector<int>& nums, int target);
    //034
public:
    static vector<int> searchRange(vector<int>& nums, int target);
    //035
public:
    static int searchInsert(vector<int>& nums, int target);
    //036
public:
    static bool isValidSudoku(vector<vector<char>>& board);
    //037
public:
    static void solveSudoku(vector<vector<char>>& board);
    //038
public:
    static string countAndSay(int n);
    //039
public:
    static vector<vector<int>> combinationSum(vector<int>& candidates, int target);

    //042
public:
    static int trap(vector<int>& height);
    //043
public:
    static string multiplyString(string num1, string num2);
    //044
public:
    static bool WildcardMatching(string s, string p);
    //045
public:
    static int jump2(vector<int>& nums);
    //046
public:
    static vector<vector<int>> permute(vector<int>& nums);
    //048
public:
    static void rotate(vector<vector<int>>& matrix);
    //049
public:
    static vector<vector<string>> groupAnagrams(vector<string>& strs);
    //050
public:
    static double myPow(double x, int n);
    //051
public:
    static vector<vector<string>> solveNQueens(int n);
    //052
public:
    static int solveNQueensII(int n);
    //053
public:
    static int maxSubArray(vector<int>& nums);
    //054
public:
    static vector<int> spiralOrder(vector<vector<int>>& matrix);
    //055
public:
    static bool canJump(vector<int>& nums);
    //056
public:
    static vector<Interval> mergeIntervals(vector<Interval>& intervals);
    //057
public:
    static vector<Interval> insertInterval(vector<Interval>& intervals, Interval newInterval);
    //058
public:
    static int lengthOfLastWord(string s);
    //059
public:
    static vector<vector<int>> generateSpiralMatrix(int n);
    //060
public:
    static string getPermutation(int n, int k);
    //061
public:
    static ListNode* rotateRight(ListNode* head, int k);
    //062
public:
    static int uniquePaths(int m, int n);
    //063
public:
    static int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid);
    //064
public:
    static int minPathSum(vector<vector<int>>& grid);
    //065
public:
    static bool isValidNumber(string s);
    //066
public:
    static vector<int> plusOne(vector<int>& digits);
    //067
public:
    static string addBinary(string a, string b);
    //068
public:
    static vector<string> fullJustify(vector<string>& words, int maxWidth);
    //069
public:
    static int mySqrt(int x);
    //070
public:
    static int climbStairs(int n);
    //071
public:
    static string simplifyPath(string path);
    //072
public:
    static int minDistance(string word1, string word2);
    //073
public:
    static void setZeroes(vector<vector<int>>& matrix);
    //074
public:
    static bool searchMatrix(vector<vector<int>>& matrix, int target);
    //075
public:
    static void sortColors(vector<int>& nums);
    //076
public:
    static string minWindow(string s, string t);
    //077
public:
    static vector<vector<int>> combine(int n, int k);
    //078
public:
    static vector<vector<int>> subsets(vector<int>& nums);
    //079
public:
    static bool exist(vector<vector<char>>& board, string word);
    //080
public:
    static int removeDuplicatesII(vector<int>& nums);
    //081
public:
    static bool searchII(vector<int>& nums, int target);
    //082
public:
    static ListNode* deleteDuplicates(ListNode* head);
    //083
public:
    static ListNode* deleteDuplicatesII(ListNode* head);
    //084
public:
    static int largestRectangleArea(vector<int>& heights);
    //085
public:
    static int maximalRectangle(vector<vector<char>>& matrix);
    //086
public:
    static ListNode* partitionList(ListNode* head, int x);
    //087
public:
    static bool isScramble(string s1, string s2);
    //088
public:
    static void mergeArray(vector<int>& nums1, int m, vector<int>& nums2, int n);
    //089
public:
    static vector<int> grayCode(int n);
    //090
public:
    static vector<vector<int>> subsetsWithDup(vector<int>& nums);
    //091
public:
    static int numDecodings(string s);
    //092
public:
    static ListNode* reverseBetween(ListNode* head, int m, int n);
    //093
public:
    static vector<string> restoreIpAddresses(string s);
    //094
public:
    static vector<int> inorderTraversal(TreeNode* root);
    //095
public:
    static vector<TreeNode*> generateTrees(int n);
    //096
public:
    static int numTrees(int n);
    //097
public:
    static bool isInterleave(string s1, string s2, string s3);
    //098
public:
    static bool isValidBST(TreeNode* root);
    //099
public:
    static void recoverTree(TreeNode* root);
    //100
public:
    static bool isSameTree(TreeNode* p, TreeNode* q);
    //101
public:
    static bool isSymmetric(TreeNode* root);
    //102
public:
    static vector<vector<int>> levelOrder(TreeNode* root);
    //103
public:
    static vector<vector<int>> zigzagLevelOrder(TreeNode* root);
    //104
public:
    static int maxDepth(TreeNode* root);
    //105
public:
    static TreeNode* buildTree(vector<int> preorder, vector<int> inorder);
    //107
public:
    static vector<vector<int>> levelOrderBottom(TreeNode* root);
    //108
public:
    static TreeNode* sortedArrayToBST(vector<int> nums);
    //109
public:
    static TreeNode* sortedListToBST(ListNode* head);
    //110
public:
    static bool isBalanced(TreeNode* root);
    //111
public:
    static int minDepth(TreeNode* root);
    //112
public:
    static bool hasPathSum(TreeNode* root, int sum);
    //113
public:
    static vector<vector<int>> pathSum(TreeNode* root, int sum);
    //114
public:
    static void flatten(TreeNode* root);
    //115
public:
    static int numDistinct(string s, string t);
    //116
public:
    static void connect(TreeLinkNode *root);
    //117
public:
    static void connectII(TreeLinkNode *root);
    //118
public:
    static vector<vector<int>> generatePascalTriangle(int numRows);
    //120
public:
    static int minimumTotal(vector<vector<int>> triangle);
    //121
public:
    static int maxProfit(vector<int>& prices);
    //122
public:
    static int maxProfitII(vector<int>& prices);
    //123
public:
    static int maxProfitIII(vector<int>& prices);
    //124
public:
    static int maxPathSum(TreeNode* root);
    //125
public:
    static bool isPalindrome(string s);
    //126
public:
    static vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList);
    //127
public:
    static int ladderLength(string beginWord, string endWord, vector<string>& wordList);
    //128
public:
    static int longestConsecutive(vector<int>& nums);
    //129
public:
    static int sumNumbers(TreeNode* root);
    //130
public:
    static void SurroundedRegions(vector<vector<char>>& board);
    //131
public :
    static vector<vector<string>> PalindromePartition(string s);
	//132
public:
	static int PalindromePartitionII(string s);
    //133
public:
    static UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node);
    //134
public:
    static int canCompleteCircuit(vector<int>& gas, vector<int>& cost);
    //135
public:
    static int candy(vector<int>& ratings);
    //136
public:
    static int singleNumber(vector<int>& nums);
    //137
public:
    static int singleNumberII(vector<int>& nums);
    //138
public:
    static RandomListNode *copyRandomList(RandomListNode *head);
    //139
public:
    static bool wordBreak(string s, vector<string>& wordDict);
    //140
public:
    static vector<string> wordBreakII(string s, vector<string>& wordDict);
    //141
public:
    static bool hasCycle(ListNode *head);
    //142
public:
    static ListNode *detectCycle(ListNode *head);
    //143
public:
    static void reorderList(ListNode* head);
    //144
public:
    static vector<int> preorderTraversal(TreeNode* root);
    //145
public:
    static vector<int> postorderTraversal(TreeNode* root);
    //147
public:
    static ListNode* insertionSortList(ListNode* head);
    //148
public:
    static ListNode* sortList(ListNode* head);
    //149
public:
    static int maxPoints(vector<Point>& points);
};