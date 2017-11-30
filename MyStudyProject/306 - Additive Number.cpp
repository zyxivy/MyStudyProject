//Additive number is a string whose digits can form additive sequence.
//A valid additive sequence should contain at least three numbers.Except for the first two numbers, each subsequent number in the sequence must be the sum of the preceding two.
//For example :
//"112358" is an additive number because the digits can form an additive sequence : 1, 1, 2, 3, 5, 8.
//1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8
//"199100199" is also an additive number, the additive sequence is : 1, 99, 100, 199.
//1 + 99 = 100, 99 + 100 = 199
//
//Note : Numbers in the additive sequence cannot have leading zeros, so sequence 1, 2, 03 or 1, 02, 3 is invalid.
//    Given a string containing only digits '0' - '9', write a function to determine if it's an additive number.
//    Follow up :
//How would you handle overflow for very large input integers ?
#include "Header.h";

bool Solution::isAdditiveNumber(string num) {
    if (num.empty() || num.length() <= 2 ) {
        return false;
    }
    int n = num.length();

    for (int i = 1; i <= n / 2; i++) {
        for (int j = 1; j <= (n - i) / 2; j++) {
            string n1 = num.substr(0, i);
            string n2 = num.substr(i, j);
            if ((n1.length() >1 && n1[0] == '0') || (n2.length() > 1 && n2[0] == '0')) {
                break;
            }
            string sum = to_string(stol(n1) + stol(n2));
            int p = i + j;
            while (p < n && sum == num.substr(p, sum.size())) {
                n1 = n2;
                n2 = sum;
                sum = to_string(stol(n1) + stol(n2));
                p = p + n2.size();
            }
            if (p == n) {
                return true;
            }
        }
    }
    return false;
}