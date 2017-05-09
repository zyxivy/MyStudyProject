//Determine whether an integer is a palindrome.Do this without extra space.

#include "Header.h"

bool Solution::isPalindrome(int x) {
    if (x < 0)
        return false;

    //get the number of digits
    int tmp = x;
    int digits = 0;
    while (tmp > 0) {
        tmp /= 10;
        digits++;
    }
    if (digits == 1)
        return true;

    while (digits > 1) {
        if (x % 10 != x / (int)pow(10, digits - 1)) {
            return false;
        }
        x %= (int)pow(10, digits - 1);
        x /= 10;
        digits -= 2;
    }
    return true;
}