//Given an array of meeting time intervals consisting of start and end times[[s1, e1], [s2, e2], ...] find the minimum number of conference rooms required.

#include "Header.h";
int minMeetingRooms(vector<Interval> intervals) {
    map<int, int >points;
    for (auto i : intervals) {
        points[intervals[i].start]++;
        points[intervals[i].end]--;
    }
    int maxRoom = 0;
    int room = 0;
    for (auto p : points) {
        room += p.second;
        maxRoom = maxRoom < room ? room : maxRoom;
    }
    return maxRoom;
}
