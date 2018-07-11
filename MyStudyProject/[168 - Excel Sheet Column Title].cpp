//Given a positive integer, return its corresponding column title as appear in an Excel sheet.
//For example :
//1->A
//2->B
//3->C
//...
//26->Z
//27->AA
//28->AB

#include "Header.h";

//The key is n--.A map to 1 not 0;

string Solution::convertToTitle(int n) {
    string str;
    if (n <= 0) {
        return str;
    }
    while (n > 0) {
        n--;
        int remainder = n % 26;
        str.insert(str.begin(), remainder + 'A');
        n = n / 26;
    }
    return str;
}