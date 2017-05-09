//The count - and-say sequence is the sequence of integers beginning as follows :
//1, 11, 21, 1211, 111221, ...
//
//1 is read off as "one 1" or 11.
//11 is read off as "two 1s" or 21.
//21 is read off as "one 2, then one 1" or 1211.
//Given an integer n, generate the nth sequence.
//
//Note: The sequence of integers will be represented as a string.

#include "Header.h";

string Solution::countAndSay(int n) {
    string str = "1";
    while (--n) {
        string newstring = "";
        int count = 1;
        int i = 1;

        while (i <= str.length()) {
            while (i < str.length()) {
                if (str[i] == str[i - 1]) {
                    count++;
                    i++;
                }
                else {
                    break;
                }
            }
            newstring += count + '0';
            newstring += str[i - 1];
            count = 1;
            i++;
        }


        str = newstring;
    }
    return str;
}