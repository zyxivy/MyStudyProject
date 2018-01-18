//Write a function that takes a string as input and reverse only the vowels of a string.
//Example 1:
//Given s = "hello", return "holle".
//Example 2 :
//    Given s = "leetcode", return "leotcede".
//    Note :
//    The vowels does not include the letter "y".

#include "Header.h";
string Solution::reverseVowels(string s) {
    int i = 0, j = s.size() - 1;
    set<char> st = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U' };
    while (i < j) {
        while (i<j && st.find(s[i]) == st.end()) {
            i++;
        }
        while (i<j && st.find(s[j]) == st.end()) {
            j--;
        }
        swap(s[i++], s[j--]);
    }
    return s;
}