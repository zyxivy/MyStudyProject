//Given n non - negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.
//
//
//Above is a histogram where width of each bar is 1, given height = [2, 1, 5, 6, 2, 3].
//
//
//The largest rectangle is shown in the shaded area, which has area = 10 unit.
//
//For example,
//Given heights = [2, 1, 5, 6, 2, 3],
//return 10.

#include "Header.h";
int Solution::largestRectangleArea(vector<int>& hist) {
    // Create an empty stack. The stack holds indexes of hist[] array
    // The bars stored in stack are always in increasing order of their
    // heights.
    vector<int> s;

    int max_area = 0; // Initalize max area
    int tp;  // To store top of stack
    int area_with_top; // To store area with top bar as the smallest bar

                       // Run through all bars of given histogram
    int i = 0;
    while (i < hist.size())
    {
        // If this bar is higher than the bar on top stack, push it to stack
        if (s.empty() || hist[s.back()] <= hist[i])
            s.push_back(i++);

        // If this bar is lower than top of stack, then calculate area of rectangle 
        // with stack top as the smallest (or minimum height) bar. 'i' is 
        // 'right index' for the top and element before top in stack is 'left index'
        else
        {
            tp = s.back();  // store the top index
            s.pop_back();  // pop the top

                      // Calculate the area with hist[tp] stack as smallest bar
            area_with_top = hist[tp] * (s.empty() ? i : i - s.back() - 1);

            // update max area, if needed
            if (max_area < area_with_top)
                max_area = area_with_top;
        }
    }

    // Now pop the remaining bars from stack and calculate area with every
    // popped bar as the smallest bar
    while (s.empty() == false)
    {
        tp = s.back();
        s.pop_back();
        area_with_top = hist[tp] * (s.empty() ? i : i - s.back() - 1);

        if (max_area < area_with_top)
            max_area = area_with_top;
    }

    return max_area;

}