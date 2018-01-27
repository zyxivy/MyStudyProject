//Given a data stream input of non - negative integers a1, a2, ..., an, ..., summarize the numbers seen so far as a list of disjoint intervals.
//For example, suppose the integers from the data stream are 1, 3, 7, 2, 6, ..., then the summary will be :
//[1, 1]
//[1, 1], [3, 3]
//[1, 1], [3, 3], [7, 7]
//[1, 3], [7, 7]
//[1, 3], [6, 7]
//Follow up :
//What if there are lots of merges and the number of disjoint intervals are small compared to the data stream's size? 

#include "Header.h";
/**
* Definition for an interval.
* struct Interval {
*     int start;
*     int end;
*     Interval() : start(0), end(0) {}
*     Interval(int s, int e) : start(s), end(e) {}
* };
*/
class SummaryRanges {
    vector<Interval> intervals;

    int intervalBinarySearch(vector<Interval> in, int start, int end, int target) {
        if (start > end) {
            return start;
        }

        int mid = (start + end) / 2;
        if (in[mid].start <= target && in[mid].end >= target) {
            return mid;
        }
        else if (in[mid].start > target) {
            return intervalBinarySearch(in, start, mid - 1, target);
        }
        else {
            return intervalBinarySearch(in, mid + 1, end, target);
        }
    }
public:
    /** Initialize your data structure here. */
    SummaryRanges() {

    }

    void addNum(int val) {
        if (intervals.empty()) {
            Interval in(val, val);
            intervals.push_back(in);
            return;
        }

        int sz = intervals.size();
        int i = intervalBinarySearch(intervals, 0, sz - 1, val);

        if (i == sz) {
            if (intervals[i - 1].start <= val && intervals[i - 1].end >= val) {
                return;
            }
            else
            if (intervals[i - 1].end == val - 1) {
                intervals[i - 1].end = val;
            }
            else {
                Interval in(val, val);
                intervals.push_back(in);
            }
            return;
        }

        if (i == 0) {
            if (intervals[i].start <= val && intervals[i].end >= val) {
                return;
            }
            else if (intervals[i].start == val + 1) {
                intervals[i].start = val;
            }
            else {
                Interval in(val, val);
                intervals.insert(intervals.begin(), in);
            }
            return;
        }

        //val is in one of the intervals;
        if (intervals[i].start <= val && intervals[i].end >= val) {
            return;
        }

        //val is isolated.
        if (intervals[i - 1].end < val - 1 && intervals[i].start > val + 1) {
            Interval in(val, val);
            intervals.insert(intervals.begin() + i, in);
            return;
        }

        //val is -1 smaller than the start
        if (intervals[i].start == val + 1) {
            intervals[i].start = val;
        }

        //val is +1 bigger than previous end
        if (i - 1 >= 0 && intervals[i - 1].end == val - 1) {
            intervals[i - 1].end = val;
        }

        if (intervals[i - 1].end >= intervals[i].start) {
            intervals[i - 1].end = intervals[i].end;
            intervals.erase(intervals.begin() + i);
        }
    }

    vector<Interval> getIntervals() {
        return intervals;
    }
};

//int main() {
//    SummaryRanges sr;
//    sr.addNum(6);
//    sr.addNum(6);
//    sr.addNum(0);
//    sr.addNum(4);
//    sr.addNum(2);
//    sr.addNum(0);
//}
