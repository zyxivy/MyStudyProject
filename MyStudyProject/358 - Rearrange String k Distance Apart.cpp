//Given a non - empty string str and an integer k, 
//rearrange the string such that the same characters are at least distance k from each other.
//All input strings are given in lowercase letters.If it is not possible to rearrange the string, return an empty string "".
//Example 1:
//str = "aabbcc", k = 3
//
//Result : "abcabc"
//
//    The same letters are at least distance 3 from each other.
//    Example 2 :
//    str = "aaabc", k = 3
//
//    Answer : ""
//
//    It is not possible to rearrange the string.
//    Example 3 :
//    str = "aaadbbcc", k = 2
//
//    Answer : "abacabcd"
//
//    Another possible answer is : "abcabcda"
//
//    The same letters are at least distance 2 from each other.

#include "Header.h";
//This is a greedy problem.
//Every time we want to find the best candidate : which is the character with the largest remaining count.Thus we will be having two arrays.
//One count array to store the remaining count of every character.Another array to keep track of the most left position that one character can appear.
//We will iterated through these two array to find the best candidate for every position.Since the array is fixed size, it will take constant time to do this.
//After we find the candidate, we update two arrays.
string Solution::rearrangeString(string str, int k) {
    vector<int> count(26, 0);
    vector<int> validPos(26, 0);
    string ans;
    if (k > 26) {
        return "";
    }
    for (char c : str) {
        count[c - 'a']++;
    }
    for (int i = 0; i < str.length(); i++) {
        int candidate = -1;
        int max = INT_MIN;
        for (int j = 0; j < 26; j++) {
            if (count[j] > 0 && count[j] > max&& i > validPos[j]) {
                candidate = j;
                max = count[j]; 
            }
        }
        if (candidate == -1) {
            return "";
        }
        count[candidate]--;
        validPos[candidate] = i + k;
        ans.push_back('a' + candidate);
    }
    return ans;
}