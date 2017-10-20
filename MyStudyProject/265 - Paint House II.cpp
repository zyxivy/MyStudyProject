//There are a row of n houses, each house can be painted with one of the k colors.
//The cost of painting each house with a certain color is different.
//You have to paint all the houses such that no two adjacent houses have the same color.
//The cost of painting each house with a certain color is represented by a n x k cost matrix.
//For example, costs[0][0] is the cost of painting house 0 with color 0; 
//costs[1][2] is the cost of painting house 1 with color 2, and so on… 
//Find the minimum cost to paint all houses.
//Note:
//All costs are positive integers.

#include "Header.h";
int Solution::minCostII(vector<vector<int>> costs) {
    if (costs.size() == 0) {
        return 0;
    }
    int min1 = 0;
    int min2 = 0;
    int idx = 0;
    for (vector<int> cost : costs) {
        int temp;
        int tempMin1 = INT_MAX;
        int tempMin2 = INT_MAX;
        int tempIDX = 0;
        for (int i = 0; i < cost.size(); i++) {
            temp = ((i != idx) ? min1 : min2) + cost[i];
            if (temp <= tempMin1) {
                tempIDX = i;
                tempMin2 = tempMin1;
                tempMin1 = temp;
            }
            else if (temp <= tempMin2) {
                tempMin2 = temp;
            }
        }
        min1 = tempMin1;
        min2 = tempMin2;
        idx = tempIDX;
    }
    return min1;
}