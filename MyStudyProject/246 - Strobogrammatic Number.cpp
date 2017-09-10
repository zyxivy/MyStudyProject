//strobogrammatic number is a number that looks the same when rotated 180 degrees(looked at upside down).
//Write a function to determine if a number is strobogrammatic.The number is represented as a string.
//For example, the numbers "69", "88", and "818" are all strobogrammatic.
#include "Header.h";
bool Solution::isStrobogrammatic(string num) {
    map<char, char> mp;
    mp['1'] = '1';
    mp['8'] = '8';
    mp['0'] = '0';
    mp['6'] = '9';
    mp['9'] = '6';
    int i = 0;
    int j = num.size() - 1;
    while(i<j) {
        if (mp.find(num[i]) == mp.end()|| mp.find(num[j]) == mp.end()) {
            return false;
        }
        if (mp[num[i]] != num[j]|| mp[num[j]] != num[i]) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}