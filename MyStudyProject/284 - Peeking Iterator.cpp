//Given an Iterator class interface with methods : next() and hasNext(), 
//design and implement a PeekingIterator that support the peek() operation 
//-- it essentially peek() at the element that will be returned by the next call to next().
//
//Here is an example.Assume that the iterator is initialized to the beginning of the list : [1, 2, 3].
//Call next() gets you 1, the first element in the list.
//Now you call peek() and it returns 2, the next element.Calling next() after that still return 2.
//You call next() the final time and it returns 3, the last element.Calling hasNext() after that should return false.
//Follow up : How would you extend your design to be generic and work with all types, not just integer ?

#include "Header.h";
class Iterator {
    struct Data;
    Data* data;
public:
    Iterator(const vector<int>& nums);
    Iterator(const Iterator& iter);
    virtual ~Iterator();
    // Returns the next element in the iteration.
    int next();
    // Returns true if the iteration has more elements.
    bool hasNext() const;
};

class PeekingIterator : public Iterator {

public:

    PeekingIterator(const vector<int>& nums) : Iterator(nums), has_next_(Iterator::hasNext()) {
        // Initialize any member here.
        // **DO NOT** save a copy of nums and manipulate it directly.
        // You should only use the Iterator interface methods.
    }
    // Returns the next element in the iteration without advancing the iterator.
    int peek() {
        if (!has_peeked_) {
            has_peeked_ = true;
            val_ = Iterator::next();
        }
        return val_;
    }
    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next() {
        val_ = peek();
        has_peeked_ = false;
        has_next_ = Iterator::hasNext();
        return val_;
    }    

    bool hasNext() const {
        return has_next_;
    }
private:
    int val_;
    bool has_next_;
    bool has_peeked_ = false;
};