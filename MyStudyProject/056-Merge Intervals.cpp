//Given a collection of intervals, merge all overlapping intervals.
//
//For example,
//Given[1, 3], [2, 6], [8, 10], [15, 18],
//return[1, 6], [8, 10], [15, 18].
#include "Header.h";

int partition(vector<Interval>& intervals, int l, int r) {
    int pivot = intervals[r].start;
    int wall = l;
    while (l < r) {
        if (intervals[l].start <= pivot) {
            Interval tmp(intervals[l].start, intervals[l].end);
            intervals[l].start = intervals[wall].start;
            intervals[l].end = intervals[wall].end;
            intervals[wall].start = tmp.start;
            intervals[wall].end = tmp.end;
            wall++;
        }
        l++;
    }
    Interval tmp(intervals[r].start, intervals[r].end);
    intervals[r].start = intervals[wall].start;
    intervals[r].end = intervals[wall].end;
    intervals[wall].start = tmp.start;
    intervals[wall].end = tmp.end;
    return wall;
}

void quicksort(vector<Interval>& intervals, int l, int r) {
    if (l < r) {
        int p = partition(intervals, l, r);
        quicksort(intervals, l, p - 1);
        quicksort(intervals, p + 1, r);
    }
}

vector<Interval> Solution::mergeIntervals(vector<Interval>& intervals) {
    quicksort(intervals, 0, intervals.size() - 1);
    int i = 0;
    while (i < intervals.size()) {
        int j = i + 1;
        while (j < intervals.size()) {
            if (intervals[j].start <= intervals[i].end) {
                intervals[i].end = intervals[i].end>intervals[j].end ? intervals[i].end : intervals[j].end;
                intervals.erase(intervals.begin() + j);
            }
            else {
                break;
            }
        }
        i = j;
    }
    return intervals;
}