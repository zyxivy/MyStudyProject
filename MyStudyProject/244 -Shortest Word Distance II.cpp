//This is a follow up of Shortest Word Distance.The only difference is now you are given the list of words and your method will be called repeatedly many times with different parameters.How would you optimize it ?
//Design a class which receives a list of words in the constructor, and implements a method that takes two words word1 and word2 and return the shortest distance between these two words in the list.
//For example,
//Assume that words = ["practice", "makes", "perfect", "coding", "makes"].
//Given word1 = "coding”, word2 = "practice”, return 3. Given word1 = "makes", word2 = "coding", return 1.
//Note
//You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.

#include "Header.h";
class WordDistance {
private:
    map<string, vector<int>> mp;

public:
    WordDistance(vector<string> words) {
        for (int i = 0; i < words.size(); i++) {
            mp[words[i]].push_back(i);
        }
    }

    int shortest(string word1, string word2) {
        int result = 0;

        int i = 0;
        int j = 0;
        vector<int> list1 = mp[word1];
        vector<int> list2 = mp[word2];
        while (i < list1.size() && j < list2.size()) {
            int dis = list1[i] < list2[j] ? list2[j] - list1[i] : list1[i] - list2[j];
            result = result < dis ? result : dis;

            if (list1[i] < list2[j]) {
                i++;
            }
            else{
                j++;
            }
        }

        return result;
    }
};