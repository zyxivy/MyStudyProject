//Design and implement a TwoSum class.It should support the following operations : add and find.
//add  - Add the number to an internal data structure.
//find  - Find if there exists any pair of numbers which sum is equal to the value.
//For example,
//add(1); add(3); add(5);
//find(4) -> true
//find(7) -> false

#include "Header.h";

TwoSumIII::TwoSumIII(){

}
void TwoSumIII::add(int number) {
    if (elements.find(number) != elements.end()) {
        elements[number] = elements[number] + 1;
    }
    else {
        elements[number] = 1;
    }
}
bool TwoSumIII::find(int value) {
    for (map<int, int>::iterator it = elements.begin(); it != elements.end();it++) {
        int target = value - it->second;
        if (elements.find(target) != elements.end()) {
            if (target == value - it->second && elements[target]>2) {
                continue;
            }
            return true;
        }
    }
    return false;
}