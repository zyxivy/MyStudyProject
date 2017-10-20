#pragma once

using namespace std;
#include <string>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <math.h>
#include <iostream>
#include <unordered_set>
#include <queue>

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

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack();

    void push(int x);

    void pop();

    int top();

    int getMin();

private:
    vector<int> stack;
    vector<int> minTrack;
};

class TwoSumIII {
public:
    TwoSumIII();
    void add(int number);
    bool find(int value);
private:
    map<int, int> elements;
};

class BSTIterator {
public:
    BSTIterator(TreeNode *root);
    /** @return whether we have a next smallest number */
    bool hasNext();
    /** @return the next smallest number */
    int next();
private:
    TreeNode* m_root;
};

class TrieNode {
public:
    char m_c;
    map<char, TrieNode*> children;
    bool isLeaf;
    TrieNode() { isLeaf = false; };
    TrieNode(char c) {
        m_c = c; 
        isLeaf = false;
    };
};
class Trie {
public:
    /** Initialize your data structure here. */

    Trie();
    /** Inserts a word into the trie. */
    void insert(string word);

    /** Returns if the word is in the trie. */
    bool search(string word);

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix);

private:
    TrieNode* root;
    TrieNode* searchNode(string word);
};

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary();

    /** Adds a word into the data structure. */
    void addWord(string word);

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word);
private:
    TrieNode* root;
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
    static int maxSubArray(vector<int>& nums);
    //054
    static vector<int> spiralOrder(vector<vector<int>>& matrix);
    //055
    static bool canJump(vector<int>& nums);
    //056
    static vector<Interval> mergeIntervals(vector<Interval>& intervals);
    //057
    static vector<Interval> insertInterval(vector<Interval>& intervals, Interval newInterval);
    //058
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
    //150
public:
    static int evalRPN(vector<string>& tokens);
    //151
public:
    static void reverseWords(string &s);
    //152
public:
    static int maxProduct(vector<int>& nums);
    //153
public:
    static int findMin(vector<int>& nums);
    //154
public:
    static int findMinII(vector<int>& nums);
    //156
public:
    static TreeNode *upsideDownBinaryTree(TreeNode *root);
    //157
public:
    static int read(char *buf, int n);
    //159
public:
    static int lengthOfLongestSubstringTwoDistinct(string s);
    //160
public:
    static ListNode *getIntersectionNode(ListNode *headA, ListNode *headB);
    //161
public:
    static bool oneEditDistance(string word1, string word2);
    //162
public:
    static int findPeakElement(vector<int>& nums);
    //163
public:
    static vector<string> findMissingRanges(vector<int> nums, int start, int end);
    //164
public:
    static int maximumGap(vector<int>& nums);
    //165
public:
    static int compareVersion(string version1, string version2);
    //166
public:
    static string fractionToDecimal(int numerator, int denominator);
    //167
public:
    static vector<int> twoSumII(vector<int>& numbers, int target);
    //189
public:
    static string convertToTitle(int n);
    //169
public:
    static int majorityElement(vector<int>& nums);
    //171
public:
    static int titleToNumber(string s);
    //172
public:
    static int trailingZeroes(int n);
    //174
public:
    static int calculateMinimumHP(vector<vector<int>>& dungeon);
    //179
public:
    static string largestNumber(vector<int>& nums);
    //187
public:
    static vector<string> findRepeatedDnaSequences(string s);
    //188
public:
    static int maxProfit(int k, vector<int>& prices);
    //189
public:
    static void rotate(vector<int>& nums, int k);
    //190
public:
    static uint32_t reverseBits(uint32_t n);
    //191
public:
    static int hammingWeight(uint32_t n);
    //198
public:
    static int rob(vector<int>& nums);
    //199
public:
    static vector<int> rightSideView(TreeNode* root);
    //200
public:
    static int numIslands(vector<vector<char>>& grid);
    //201
public:
    static int rangeBitwiseAnd(int m, int n);
    //202
public:
    static bool isHappy(int n);
    //203
public:
    static ListNode* removeElements(ListNode* head, int val);
    //204
public: 
    static int countPrimes(int n);
    //205
public:
    static bool isIsomorphic(string s, string t);
    //205
public:
    static ListNode* reverseList(ListNode* head);
    //207
public:
    static bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites);
    //209
public:
    static int minSubArrayLen(int s, vector<int>& nums);
    //210
public:
    static vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites);
    //212
public:
    static vector<string> findWords(vector<vector<char>>& board, vector<string>& words);
    //213
public:
    static int robII(vector<int>& nums);
    //214
public:
    static string shortestPalindrome(string s);
    //215
public:
    static int findKthLargest(vector<int>& nums, int k);
    //216
public:
    static vector<vector<int>> combinationSum3(int k, int n);
    //217 
public:
    static bool containsDuplicate(vector<int>& nums);
    //218
    static vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings);
	//219  
	static bool containsNearbyDuplicate(vector<int>& nums, int k);
	//220 
	static bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t);
	//221
	static int maximalSquare(vector<vector<int>>& matrix);
	//222
	static int countNodes(TreeNode* root);
	//223
	static int computeArea(int A, int B, int C, int D, int E, int F, int G, int H);
	//224
	static int calculate(string s);
    //226
    static TreeNode* invertTree(TreeNode* root);
    //227
    static int calculateII(string s);
    //228 
    static vector<string> summaryRanges(vector<int>& nums);
    //229
    static vector<int> majorElement(vector<int>& nums);
    //230
    static int kthSmallest(TreeNode* root, int k);
    //231
    static bool isPowerOfTwo(int n);
    //233
    static int countDigitOne(int n);
    //234
    static bool isPalindrome(ListNode* head);
    //235
    static TreeNode* lowestCommonBinaryAncestor(TreeNode* root, TreeNode* p, TreeNode* q);
    //236
    static TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q);
    //237
    static void deleteNode(ListNode* node);
    //238
    static vector<int> productExceptSelf(vector<int>& nums);
    //239
    static vector<int> maxSlidingWindow(vector<int>& nums, int k);
    //240
    static bool searchMatrix2D(vector<vector<int>>& matrix, int target);
    //241
    static vector<int> diffWaysToCompute(string input);
    //242
    static bool isAnagram(string s, string t);
    //243
    static int shortestDistance(vector<string> words, string word1, string word2);
    //245
    static int shortestWordDistanceIII(vector<string> words, string word1, string word2);
    //246
    static bool isStrobogrammatic(string num);
    //247
    static vector<string> findStrobogrammatic(int n);
    //248
    static int strobogrammaticInRange(string low, string high);
    //249
    static vector<vector<string>> groupStrings(vector<string>& strings);
    //250
    static int countUnivalSubtrees(TreeNode* root);
    //254
    static vector<vector<int>> Solution::getFactors(int n);
    //255
    static bool verifyPreorder(vector<int> preorder);
    //256
    static int minPaintHouseCost(vector<vector<int>> costs);
    //257
    static vector<string> binaryTreePaths(TreeNode* root);
    //258
    static int addDigits(int num);
    //259
    static int threeSumSmaller(vector<int>& nums, int target);
    //260
    static vector<int> singleNumberIII(vector<int>& nums);
    //261
    static bool validTree(int n, vector<pair<int, int>>& edges);
    //263
    static bool isUgly(int num);
    //264
    static int nthUglyNumber(int n);
    //265
    static int minCostII(vector<vector<int>> costs);
    //266
    static bool Solution::canPermutePalindrome(string s);
    //267
    static vector<string> generatePalindromes(string s);
};

