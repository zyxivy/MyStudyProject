//Given a set of non - overlapping intervals, insert a new interval into the intervals(merge if necessary).
//
//You may assume that the intervals were initially sorted according to their start times.
//
//Example 1:
//Given intervals[1, 3], [6, 9], insert and merge[2, 5] in as[1, 5], [6, 9].
//
//Example 2 :
//    Given[1, 2], [3, 5], [6, 7], [8, 10], [12, 16], insert and merge[4, 9] in as[1, 2], [3, 10], [12, 16].
//
//    This is because the new interval[4, 9] overlaps with[3, 5], [6, 7], [8, 10].

#include "Header.h";

vector<Interval> Solution::insertInterval(vector<Interval>& intervals, Interval newInterval) {
    vector<Interval> ret;
    int i = 0;
    if (intervals.size() == 0) {
        ret.push_back(newInterval);
        return ret;
    }
    while (i < intervals.size()) {
        if (intervals[i].end < newInterval.start) {
            ret.push_back(intervals[i]);
            i++;
        }
        else {
            break;
        }
    }
    if (i == intervals.size()) {
        newInterval.end = intervals[intervals.size() - 1].end < newInterval.end ? newInterval.end : intervals[intervals.size() - 1].end;
        ret.push_back(newInterval);
        return ret;
    }
    newInterval.start = intervals[i].start < newInterval.start ? intervals[i].start : newInterval.start;
    while (i < intervals.size()) {
        if (intervals[i].start <= newInterval.end) {
            i++;
        }
        else {
            break;
        }
    }
    if (i == intervals.size()) {
        newInterval.end = intervals[intervals.size() - 1].end < newInterval.end ? newInterval.end : intervals[intervals.size() - 1].end;
        ret.push_back(newInterval);
        return ret;
    }
    newInterval.end = intervals[i-1].end < newInterval.end ? newInterval.end : intervals[i-1].end;
    ret.push_back(newInterval);
    while (i < intervals.size()) {
        ret.push_back(intervals[i]);
        i++;
    }
    return ret;
}