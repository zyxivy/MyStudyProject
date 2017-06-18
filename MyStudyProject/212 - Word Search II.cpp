//Given a 2D board and a list of words from the dictionary, find all words in the board.
//
//Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring.The same letter cell may not be used more than once in a word.
//
//For example,
//Given words = ["oath", "pea", "eat", "rain"] and board =
//
//[
//    ['o', 'a', 'a', 'n'],
//    ['e', 't', 'a', 'e'],
//    ['i', 'h', 'k', 'r'],
//    ['i', 'f', 'l', 'v']
//]
//Return["eat", "oath"].
//Note:
//You may assume that all inputs are consist of lowercase letters a - z.
//
//click to show hint.
//
//You would need to optimize your backtracking to pass the larger test.Could you stop backtracking earlier ?
//
//If the current candidate does not exist in all words' prefix, you could stop backtracking immediately. 

#include "Header.h";
vector<string> Solution::findWords(vector<vector<char>>& board, vector<string>& words) {

}