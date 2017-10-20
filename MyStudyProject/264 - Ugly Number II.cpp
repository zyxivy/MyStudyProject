//Write a program to find the n - th ugly number.
//Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
//Note that 1 is typically treated as an ugly number, and n does not exceed 1690.

#include "Header.h";
int Solution::nthUglyNumber(int n) {
    vector<int> nums(1, 1);
    int p2 = 0;
    int p3 = 0;
    int p5 = 0;
    while (nums.size() < n) {
        int num2 = nums[p2] * 2;
        int num3 = nums[p3] * 3;
        int num5 = nums[p5] * 5;
        int minNum = min(num2, min(num3, num5));
        if (minNum == num2) {
            p2++;
        }
        else if (minNum == num3) {
            p3++;
        }
        else {
            p5++;
        }
        if (minNum != nums.back()) {
            nums.push_back(minNum);
        }        
    }
    return nums[nums.size() - 1];
}