//Given a positive integer num, write a function which returns True if num is a perfect square else False.
//Note: Do not use any built - in library function such as sqrt.
//    Example 1 :
//    Input : 16
//    Returns : True
//
//    Example 2 :
//    Input : 14
//    Returns : False

#include "Header.h";
bool Solution::isPerfectSquare(int num) {
    int l = 1;
    int r = num;
    while (l <= r) {
        long m = (l + r) / 2;
        long sqr = m*m;
        if (sqr == num) {
            return true;
        }
        else if (sqr < num) {
            l = m + 1;
        }
        else {
            r = m - 1;
        }
    }
    return false;
}