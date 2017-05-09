//Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.
//
//Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
//
//Note:
//You are not suppose to use the library's sort function for this problem.
//
//click to show follow up.
//
//Follow up :
//A rather straight forward solution is a two - pass algorithm using counting sort.
//First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.
//
//Could you come up with an one - pass algorithm using only constant space ?
#include "Header.h";
void Solution::sortColors(vector<int>& A) {
    int r = -1, w = -1, b = -1;
    for (int i = 0;i < A.size();i++) {
        if (A[i] == 0) {
            A[++r] = 0;

            if (w != -1) {
                A[i] = 1;
                w++;
            }
            if (b != -1) {
                A[i] = 2;
                if (w != -1) {
                    A[b] = 1;
                }
                b++;
            }

        }
        else if (A[i] == 1) {
            if (b != -1) {
                A[i] = 2;
                b++;
            }
            if (w != -1) {
                A[++w] = 1;
            }
            else {
                w = r + 1;
                A[w] = 1;
            }

            
        }
        else if (A[i] == 2) {
            if (b == -1) {
                b = i;
            }
        }
    }
    int i = 0;
    return;
}