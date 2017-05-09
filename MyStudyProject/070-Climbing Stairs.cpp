//You are climbing a stair case.It takes n steps to reach to the top.
//
//Each time you can either climb 1 or 2 steps.In how many distinct ways can you climb to the top ?

#include "Header.h";
int Solution::climbStairs(int n) {
    //if (n == 0) {
    //    return 0;
    //}
    //if (n == 1) {
    //    return 1;
    //}
    //vector<int> steps(n, 0);
    //steps[0] = 1;
    //steps[1] = 2;
    //for (int i = 2;i < n;i++) {
    //    steps[i] = steps[i - 1] + steps[i - 2];
    //}
    //return steps[n - 1];

    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    if (n == 2) {
        return 2;
    }
    int f1 = 1;
    int f2 = 2;
    int f3 = f1 + f2;
    for (int k = 3;k < n;k++) {
        int tmp = f3;
        f3 = f2 + f3;
        f1 = f2;
        f2 = tmp;
    }
    return f3;
}