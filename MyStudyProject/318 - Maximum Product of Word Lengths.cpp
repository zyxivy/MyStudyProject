//Given a string array words, find the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters.You may assume that each word will contain only lower case letters.If no such two words exist, return 0.
//Example 1:
//    Given["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]
//        Return 16
//        The two words can be "abcw", "xtfn".
//        Example 2 :
//        Given["a", "ab", "abc", "d", "cd", "bcd", "abcd"]
//        Return 4
//        The two words can be "ab", "cd".
//        Example 3 :
//        Given["a", "aa", "aaa", "aaaa"]
//        Return 0
//        No such pair of words.

#include "Header.h";

//map each word to a value (computed by binary 1<<words[i][j])
int Solution::maxProduct(vector<string>& words) {
    if (words.empty() || words.size() == 1) {
        return 0;
    }
    int maxProduct = 0;
    vector<int> values(words.size(), 0);

    for (int i = 0; i < words.size();i++) {
        for (char c : words[i]) {
            values[i] |= 1 << (c - 'a');
        }
    }

    for (int i = 0; i < values.size(); i++) {
        for (int j = i + 1; j < values.size(); j++) {
            int val1 = values[i];
            int val2 = values[j];
            if ((val1 & val2) == 0) {
                maxProduct = max(maxProduct, (int)(words[i].length()*words[j].length()));
            }
        }

    }
    return maxProduct;
}