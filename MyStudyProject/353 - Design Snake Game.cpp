//Design a Snake game that is played on a device with screen size = width x height.Play the game online if you are not familiar with the game.
//The snake is initially positioned at the top left corner(0, 0) with length = 1 unit.
//You are given a list of food's positions in row-column order. When a snake eats the food, its length and the game's score both increase by 1.
//Each food appears one by one on the screen.For example, the second food will not appear until the first food was eaten by the snake.
//When a food does appear on the screen, it is guaranteed that it will not appear on a block occupied by the snake.
//Example:
//Given width = 3, height = 2, and food = [[1, 2], [0, 1]].
//
//Snake snake = new Snake(width, height, food);
//
//Initially the snake appears at position(0, 0) and the food at(1, 2).
//
//| S| | |
//| | |F |
//
//snake.move("R");->Returns 0
//
//| |S| |
//| | |F |
//
//snake.move("D");->Returns 0
//
//| | | |
//| |S | F |
//
//snake.move("R");->Returns 1 (Snake eats the first food and right after that, the second food appears at(0, 1))
//
//| |F| |
//| |S | S |
//
//snake.move("U");->Returns 1
//
//| |F | S|
//| | |S |
//
//snake.move("L");->Returns 2 (Snake eats the second food)
//
//| |S | S|
//| | |S |
//
//snake.move("U");->Returns - 1 (Game over because snake collides with border)

#include "Header.h";
class SnakeGame {
private:
    int width;
    int height;
    int score;
    vector<pair<int, int>> food;
    deque<pair<int, int>> pos;
public:
    /** Initialize your data structure here.
    @param width - screen width
    @param height - screen height
    @param food - A list of food positions
    E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<pair<int, int>> food) {
        this->width = width;
        this->height = height;
        this->food = food;
        pos.push_back(make_pair(0, 0));
        score = 0;
    }

    /** Moves the snake.
    @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down
    @return The game's score after the move. Return -1 if game over.
    Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        pair<int, int> head = pos.front();
        pair<int, int> tail = pos.back();
        pos.pop_back();
        if (direction == "U") {
            head.first--;
        }
        else if (direction == "D") {
            head.first++;
        }
        else if (direction == "L") {
            head.second--;
        }
        else if (direction == "R") {
            head.second++;
        }

        if (count(pos.begin(), pos.end(), head) //count(InputIterator first, InputIterator last, const T& val): 
                                               //Returns the number of elements in the range [first,last) that compare equal to val.
            || head.first < 0 || head.first >= height || head.second < 0 || head.second >= width) {
            return -1;
        }
        pos.push_front(head);
        if (!food.empty() && food.front() == head) {
            food.erase(food.begin());
            pos.push_back(tail);
            score++;
        }
        return score;
    }
};