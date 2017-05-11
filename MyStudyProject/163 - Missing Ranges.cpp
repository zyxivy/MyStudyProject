//Given a sorted integer array where the range of elements are[0, 99] inclusive, return its missing ranges.For example, given[0, 1, 3, 50, 75], return[�2�, �4->49�, �51->74�, �76->99�]
//Example Questions Candidate Might Ask :
//Q: What if the given array is empty ?
//    A : Then you should return[�0->99�] as those ranges are missing.
//    Q : What if the given array contains all elements from the ranges ?
//    A : Return an empty list, which means no range is missing.
//    Solution
////    Compare the gap between two neighbor elements and output its range, simple as that right ? 
//This seems deceptively easy, except there are multiple edge cases to consider, 
//such as the first and last element, which does not have previous and next element respectively.
//Also, what happens when the given array is empty ? 
//We should output the range �0->99�.As it turns out, 
//if we could add two �artificial� elements, �1 before the first element and 100 after the last element, 
//we could avoid all the above pesky cases.

#include "Header.h";

vector<string> Solution::findMissingRanges(vector<int> nums, int start, int end) {
    vector<string> result;

    return result;
}