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

class TrieNodeFindWords {
public:

	vector<TrieNodeFindWords*> children;
	string word;

	TrieNodeFindWords() :word(""), children(vector<TrieNodeFindWords*>(26, nullptr)) {}

};

void findWordsDFS(vector<vector<char>>& board, int i, int j, vector<string>& ans, TrieNodeFindWords* curr) {
	char c = board[i][j];
	int n = c - 'a';
	if (c == '#' || curr->children[n] == nullptr) {
		return;
	}
	curr = curr->children[n];
	if (curr->word != "") {
		ans.push_back(curr->word);
		curr->word = "";
	}

	board[i][j] = '#';
	if (i > 0)
		findWordsDFS(board, i - 1, j, ans, curr);
	if (j > 0)
		findWordsDFS(board, i, j - 1, ans, curr);
	if (i < board.size() - 1)
		findWordsDFS(board, i + 1, j, ans, curr);
	if (j < board[0].size() - 1)
		findWordsDFS(board, i, j + 1, ans, curr);
	board[i][j] = c;
}

TrieNodeFindWords* buildTrie(vector<string> words) {
	TrieNodeFindWords* root = new TrieNodeFindWords();
	for (string s : words) {
		TrieNodeFindWords* curr = root;
		for (char c : s) {
			if (curr->children[c - 'a'] == nullptr) {
				curr->children[c - 'a'] = new TrieNodeFindWords();
				curr = curr->children[c - 'a'];
			}
		}
		curr->word = s;
	}
	return root;
}

vector<string> Solution::findWords(vector<vector<char>>& board, vector<string>& words) {
    vector<string> result;

	if (board.empty() || board[0].empty()) {
		return result;
	}
	TrieNodeFindWords* root = buildTrie(words);
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[0].size(); j++) {
			findWordsDFS(board, i, j, result, root);
		}
	}
    return result;
}