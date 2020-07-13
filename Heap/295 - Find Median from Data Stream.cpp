//Median is the middle value in an ordered integer list.If the size of the list is even, there is no middle value.So the median is the mean of the two middle value.
//
//For example,
//[2, 3, 4], the median is 3
//
//[2, 3], the median is(2 + 3) / 2 = 2.5
//
//Design a data structure that supports the following two operations :
//
//void addNum(int num) - Add a integer number from the data stream to the data structure.
//double findMedian() - Return the median of all elements so far.
//
//
//Example :
//
//	addNum(1)
//	addNum(2)
//	findMedian() -> 1.5
//	addNum(3)
//	findMedian() -> 2
//
//
//	Follow up :
//
//If all integer numbers from the stream are between 0 and 100, how would you optimize it ?
//If 99 % of all integer numbers from the stream are between 0 and 100, how would you optimize it ?

#include "pch.h";
class MedianFinder {
public:
    priority_queue<int> small, large; // max_heap

    /** initialize your data structure here. */
    MedianFinder() {

    }

    void addNum(int num) {
        small.push(num);
        large.push(-small.top());
        small.pop();
        if (large.size() > small.size()) { // keep median at small part
            small.push(-large.top());
            large.pop();
        }
    }

    double findMedian() {
        if (small.size() == large.size()) {
            return small.top() - (double)(small.top() + large.top()) / 2;
        }
        else {
            return small.top();
        }
    }
};


//	Follow up :
//
//If all integer numbers from the stream are between 0 and 100, how would you optimize it ?
//If 99 % of all integer numbers from the stream are between 0 and 100, how would you optimize it ?

class MedianFinderII {
public:
    priority_queue<int> small, large;

    /** initialize your data structure here. */
    MedianFinderII() {

    }

    void addNum(int num) {
    }

    double findMedian() {
        return 0;
    }
};