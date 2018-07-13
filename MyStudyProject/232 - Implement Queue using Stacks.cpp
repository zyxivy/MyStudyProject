//Implement the following operations of a queue using stacks.
//push(x) --Push element x to the back of queue.
//pop() --Removes the element from in front of queue.
//peek() --Get the front element.
//empty() --Return whether the queue is empty.
//Notes:
//You must use only standard operations of a stack -- which means only push to top, peek / pop from top, size, and is empty operations are valid.
//Depending on your language, stack may not be supported natively.You may simulate a stack by using a list or deque(double - ended queue), as long as you use only standard operations of a stack.
//You may assume that all operations are valid(for example, no pop or peek operations will be called on an empty queue).

#include "Header.h";
class MyQueue {
	stack<int> queue;
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
		stack<int> temp;
		while (!queue.empty()) {
			temp.push(queue.top());
			queue.pop();
		}
		queue.push(x);
		while (!temp.empty()) {
			queue.push(temp.top());
			temp.pop();
		}
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
		int n = queue.top();
		queue.pop();
		return n;
    }

    /** Get the front element. */
    int peek() {
		if (queue.empty()) {
			return -1;
		}
		else {
			return queue.top();
		}
    }

    /** Returns whether the queue is empty. */
    bool empty() {
		return queue.empty();
    }
};