//Design a hit counter which counts the number of hits received in the past 5 minutes.
//Each function accepts a timestamp parameter(in seconds granularity) and you may assume that calls are being made to the system in chronological order(ie, the timestamp is monotonically increasing).You may assume that the earliest timestamp starts at 1.
//It is possible that several hits arrive roughly at the same time.
//Example:
//HitCounter counter = new HitCounter();
//
//// hit at timestamp 1.
//counter.hit(1);
//
//// hit at timestamp 2.
//counter.hit(2);
//
//// hit at timestamp 3.
//counter.hit(3);
//
//// get hits at timestamp 4, should return 3.
//counter.getHits(4);
//
//// hit at timestamp 300.
//counter.hit(300);
//
//// get hits at timestamp 300, should return 4.
//counter.getHits(300);
//
//// get hits at timestamp 301, should return 3.
//counter.getHits(301);
//Follow up :
//What if the number of hits per second could be very large ? Does your design scale ?

#include "Header.h";

class HitCounter {
    vector<int> hits;
    vector<int> timestamps;
public:
    HitCounter() {
        hits.resize(300);
        timestamps.resize(300);
    }
    void hit(int timestamp) {
        timestamp = timestamp % 300;
        if (timestamp == timestamps[timestamp]) {
            hits[timestamp]++;
        }
        else {
            timestamps[timestamp] = timestamp;
            hits[timestamp] = 1;
        }
    }
    int getHits(int timestamp) {
        int count = 0;
        for (int i = 0; i < 300;i++) {
            if (timestamp - timestamps[i] <= 300) {
                count += hits[i];
            }
        }
        return count;
    }
};