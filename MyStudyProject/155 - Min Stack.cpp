//Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
//
//push(x) --Push element x onto stack.
//pop() --Removes the element on top of the stack.
//top() --Get the top element.
//getMin() --Retrieve the minimum element in the stack.
//Example:
//MinStack minStack = new MinStack();
//minStack.push(-2);
//minStack.push(0);
//minStack.push(-3);
//minStack.getMin();   --> Returns - 3.
//minStack.pop();
//minStack.top();      --> Returns 0.
//minStack.getMin();   --> Returns - 2.

#include "Header.h";
    MinStack::MinStack() {

    }

    void MinStack::push(int x) {
        stack.push_back(x);
        if (minTrack.empty() || x <= minTrack.back()) {
            minTrack.push_back(x);
        }
    }

    void MinStack::pop() {
        if (stack.empty()) {
            return;
        }
        int n = stack.back();
        if (n <= minTrack.back()) {
            minTrack.pop_back();
        }
        stack.pop_back();
    }

    int MinStack::top() {
        if (stack.empty()) {
            return 0;
        }
        return stack.back();
    }

    int MinStack::getMin() {
        if (stack.empty()) {
            return 0;
        }
        return minTrack.back();
    }