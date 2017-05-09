//Given n pairs of parentheses, write a function to generate all combinations of well - formed parentheses.
//
//For example, given n = 3, a solution set is :
//
//[
//    "((()))",
//    "(()())",
//    "(())()",
//    "()(())",
//    "()()()"
//]

#include "Header.h";
void generate(int left, int right, string curString, vector<string> &records) {

    if (left == 0 && right==0) {
        records.push_back(curString);
    }
    if (left) {
        generate(left - 1, right+1, curString+'(', records);
    }
    if (right) {
        
        generate(left, right - 1, curString+')', records);
    }
}
vector<string> Solution::generateParenthesis(int n) {
    vector<string> records;
    string curString;
    generate(n,0, curString, records);
    return records;
}