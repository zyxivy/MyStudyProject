#include "Header.h"


int main()
{


    string input003 = "1213";

    vector<int> nums1;
    vector<int> nums2;



    vector<string> strings;

    vector<vector<char>> board;
    vector<char> line1;
    line1.push_back('.');
    line1.push_back('8');
    line1.push_back('7');
    line1.push_back('6');
    line1.push_back('5');
    line1.push_back('4');
    line1.push_back('3');
    line1.push_back('2');
    line1.push_back('1');

    vector<char> line2;
    line2.push_back('.');
    line2.push_back('2');
    line2.push_back('.');
    line2.push_back('.');
    line2.push_back('.');
    line2.push_back('.');
    line2.push_back('.');
    line2.push_back('.');
    line2.push_back('.');


    vector<char> line3;
    line3.push_back('3');
    line3.push_back('.');
    line3.push_back('.');
    line3.push_back('.');
    line3.push_back('.');
    line3.push_back('.');
    line3.push_back('.');
    line3.push_back('.');
    line3.push_back('.');

    vector<char> line4;
    line4.push_back('4');
    line4.push_back('.');
    line4.push_back('.');
    line4.push_back('.');
    line4.push_back('.');
    line4.push_back('.');
    line4.push_back('.');
    line4.push_back('.');
    line4.push_back('.');

    vector<char> line5;
    line5.push_back('5');
    line5.push_back('.');
    line5.push_back('.');
    line5.push_back('.');
    line5.push_back('.');
    line5.push_back('.');
    line5.push_back('.');
    line5.push_back('.');
    line5.push_back('.');

    vector<char> line6;
    line6.push_back('6');
    line6.push_back('.');
    line6.push_back('.');
    line6.push_back('.');
    line6.push_back('.');
    line6.push_back('.');
    line6.push_back('.');
    line6.push_back('.');
    line6.push_back('.');

    vector<char> line7;
    line7.push_back('7');
    line7.push_back('.');
    line7.push_back('.');
    line7.push_back('.');
    line7.push_back('.');
    line7.push_back('.');
    line7.push_back('.');
    line7.push_back('.');
    line7.push_back('.');

    vector<char> line8;
    line8.push_back('8');
    line8.push_back('.');
    line8.push_back('.');
    line8.push_back('.');
    line8.push_back('.');
    line8.push_back('.');
    line8.push_back('.');
    line8.push_back('.');
    line8.push_back('.');

    vector<char> line9;
    line9.push_back('9');
    line9.push_back('.');
    line9.push_back('.');
    line9.push_back('.');
    line9.push_back('.');
    line9.push_back('.');
    line9.push_back('.');
    line9.push_back('.');
    line9.push_back('.');

    board.push_back(line1);
    board.push_back(line2);
    board.push_back(line3);
    board.push_back(line4);
    board.push_back(line5);
    board.push_back(line6);
    board.push_back(line7);
    board.push_back(line8);
    board.push_back(line9);



    vector<string> strs = { "Listen","to","many,","speak","to","a","few." };

    Interval int0(2, 5);
    //Interval int1(3,5);
    //Interval int2(6,7);
    //Interval int3(8,10);
    //Interval int4(12, 16);

    Interval int5(3, 4);
    vector<Interval> intervals;
    intervals.push_back(int0);
    //intervals.push_back(int1);
    //intervals.push_back(int2);
    //intervals.push_back(int3);
    //intervals.push_back(int4);

	vector<vector<int>> matrix = { { 1,0,1,0,0 },{ 1,0,1,1,1 },{ 1,1,1,1,1 },{ 1,0,0,1,0 } };


    vector<vector<char>> existBoard = {{ 'a','b', 'c', 'e'},{ 's','f', 'e', 's' },{ 'a','d', 'e', 'e' }};
    vector<int> hist = {4,2,3,2,3,1,4};
    vector<int> m1 = { 4,0,0,0, 0 };
    vector<int> m2 = { 1,2,2 };

    TreeNode* root=new TreeNode(1);
    TreeNode* left = new TreeNode(2);
    TreeNode* right = new TreeNode(3);

    TreeNode* left2 = new TreeNode(4);

    TreeNode* right2 = new TreeNode(5);
    root->left = left;
    root->right = right;
    left->left = left2;
    left->right = right2;

    vector<string> list = { "4", "13", "5", "/", "+" };

    Point p1(0, 0);    
    Point p2(94911152, 94911151);
    Point p3(94911151, 94911150);
    Point p4(9, -25);
    vector<Point> pts;
    pts.push_back(p1);
    pts.push_back(p2);
    pts.push_back(p3);
    //pts.push_back(p4);

    string words = "      ";

    ListNode* l10 = new ListNode(1);
    ListNode* l11 = new ListNode(2);
    ListNode* l12 = new ListNode(3);
    ListNode* l13 = new ListNode(4);
    ListNode* l14 = new ListNode(5);
    ListNode* l15 = new ListNode(6);

    ListNode* l20 = new ListNode(-5);
    ListNode* l21 = new ListNode(-3);
    ListNode* l22 = new ListNode(0);
    ListNode* l23 = new ListNode(7);
    ListNode* l24 = new ListNode(8);
    ListNode* l25 = new ListNode(8);

    l10->next = l11;
    l11->next = l12;
    l12->next = l13;
    l13->next = l14;
    l14->next = l15;


    //l20->next = l21;
    //l21->next = l22;
    //l22->next = l23;
    //l23->next = l24;
    //l24->next = l25;


    vector<vector<int>> nums;
    vector<int> num;
    num.push_back(1);
    num.push_back(4);
    num.push_back(2);
    num.push_back(9);
    num.push_back(3);
    num.push_back(5);

    vector<int> colors = { 5,2,1,3,4 };

    pair<int, int> pr(1, 0);
    vector<pair<int, int>> pre;
    pre.push_back(pr);
    Solution::computeArea(-1500000001,0,-1500000000,1,1500000000,0, 1500000001,1);

    //Trie obj;
    //obj.insert("abcdef");
    //obj.search("abcdef");
    //obj.startsWith("ab");

    //LRUCache cache(2);
    //cache.put(1, 1);
    //cache.put(2,2);
    //cache.get(1);
    //cache.put(3, 3);
    //cache.get(2);
    //cache.put(4,4);
    //cache.get(1);
    //cache.get(3);
    //cache.get(4);

}
