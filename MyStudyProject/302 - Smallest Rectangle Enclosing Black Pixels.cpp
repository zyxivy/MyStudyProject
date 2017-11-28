//An image is represented by a binary matrix with 0 as a white pixel and 1 as a black pixel.The black pixels are connected, i.e., there is only one black region.Pixels are connected horizontally and vertically.Given the location(x, y) of one of the black pixels, return the area of the smallest(axis - aligned) rectangle that encloses all black pixels.
//For example, given the following image :
//[
//    "0010",
//    "0110",
//    "0100"
//]
//and x = 0, y = 2,
//
//Return 6.

#include "Header.h";
//direction == true: search left
//direction == false: search right

//https://discuss.leetcode.com/topic/29006/c-java-python-binary-search-solution-with-explanation
int searchCol(vector<vector<char>>& image, int i , int y, int top, int bottom, bool direction) {
    while (i != y) {
        int mid = i + (y - i) / 2;
        int k = top;
        while (k < bottom && image[k][mid] == '0') {
            k++;
        }
        if (k < bottom == direction) {
            y = mid;
        }
        else {
            i = mid + 1;
        }
    }
    return i;
}

int searchRow(vector<vector<char>>& image, int i, int x, int left, int right, bool direction) {
    while (i != x) {
        int mid = i + (x - i) / 2;
        int k = left;
        while (k < right && image[mid][k] == '0') {
            k++;
        }
        if (k < right == direction) {
            x = mid;
        }
        else {
            i = mid + 1;
        }
    }
    return i;
}
int Solution::minArea(vector<vector<char>>& image, int x, int y) {
    int m = image.size();
    if (m == 0) {
        return 0;
    }
    int n = image[0].size();
    int left = searchCol(image, 0, y, 0, m, true);
    int right = searchCol(image, y + 1, n, 0, m, false);
    int top = searchRow(image, 0, x, left, right, true);
    int bottom = searchRow(image, x + 1, m, left, right, false);
    return (right - left) * (bottom - top);


}