//Implement the following operations of a stack using queues.
//push(x) --Push element x onto stack.
//pop() --Removes the element on top of the stack.
//top() --Get the top element.
//empty() --Return whether the stack is empty.
//Notes:
//You must use only standard operations of a queue -- which means only push to back, peek / pop from front, size, and is empty operations are valid.
//Depending on your language, queue may not be supported natively.You may simulate a queue by using a list or deque(double - ended queue), as long as you use only standard operations of a queue.
//You may assume that all operations are valid(for example, no pop or top operations will be called on an empty stack).

#include "Header.h";
class MyStack {
private:
    queue<int> q;
public:
    /** Initialize your data structure here. */
    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
        int size = q.size();
        while (size > 1) {
            int n = q.front();
            q.pop();
            q.push(n);
            size--;
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int num = q.front();
        q.pop();
        return num;
    }

    /** Get the top element. */
    int top() {
        int num = q.front();
        return num;
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
};

//int main() {
//    MyStack stack;
//    stack.push(1);
//    stack.push(2);
//    stack.pop();
//}