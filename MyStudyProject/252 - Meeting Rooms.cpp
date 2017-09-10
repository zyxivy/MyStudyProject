////Given an array of meeting time intervals consisting of start and end times[[s1, e1], [s2, e2], ...](si < ei), determine if a person could attend all meetings.
//For example,
//Given[[0, 30], [5, 10], [15, 20]],
//return 2.
#include "Header.h";
class IntervalII {
public:
    int start;
    int end;
    IntervalII(int s, int e) {
        start = s;
        end = e;
    }
};

 int compareIntervals(const void* int1, const void* int2) {
     IntervalII* i1 = (IntervalII*)int1;
     IntervalII* i2 = (IntervalII*)int2;
     if (i1->start < i2->start) {
         return -1;
     }
     else if (i1->start > i2->start) {
         return 1;
     }
     else return 0;
}
bool canAttendMeetings(vector<IntervalII> intervals) {
    qsort(&(intervals[0]),intervals.size(), sizeof(IntervalII), compareIntervals);
    for (int i = 0; i < intervals.size() - 1;i++) {
        if (intervals[i].end > intervals[i + 1].start) {
            return false;
        }
    }
    return true;
}