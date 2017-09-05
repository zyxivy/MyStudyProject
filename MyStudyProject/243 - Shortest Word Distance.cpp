//Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.
//For example,
//Assume that words = ["practice", "makes", "perfect", "coding", "makes"].
//Given word1 = “coding”, word2 = “practice”, return 3.
//Given word1 = "makes", word2 = "coding", return 1.

#include "Header.h";
int Solution::shortestDistance(vector<string> words, string word1, string word2) {
    int m = -1;
    int n = -1;
    int result = INT_MAX;
    for (int i = 0; i < words.size(); i++) {
        if (words[i].compare(word1) != 0) {
            m = i;
            if (n != -1) {
                result = result < m - n ? result : m - n;
            }
        }
        else if (words[i].compare(word2) != 0) {
            n = i;
            if (m != -1) {
                result = result < n - m ? result : n - m;
            }
        }
    }
    return result;
}