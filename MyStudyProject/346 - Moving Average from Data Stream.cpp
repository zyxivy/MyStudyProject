//Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.
//For example,
//1
//2
//3
//4
//5
//MovingAverage m = new MovingAverage(3);
//m.next(1) = 1
//m.next(10) = (1 + 10) / 2
//m.next(3) = (1 + 10 + 3) / 3
//m.next(5) = (10 + 3 + 5) / 3

#include "Header.h";
class MovingAverage {
private:
    queue<int> qu;
    int window;
    double sum;
public:
    MovingAverage(int size) :window(size), sum(0) {}

    double next(int val) {
        sum += val;
        qu.push(val);
        int queueSize = (int)qu.size();
        if (queueSize <= window) {
            return sum / queueSize;
        }
        else {
            sum -= qu.front();
            qu.pop();
            return sum / window;
        }
    }
};