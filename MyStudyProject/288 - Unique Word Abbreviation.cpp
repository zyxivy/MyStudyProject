//An abbreviation of a word follows the form <first letter><number><last letter>.Below are some examples of word abbreviations :
//a) it--> it(no abbreviation)
//
//1
//b) d | o | g--> d1g
//
//1    1  1
//1-- - 5----0----5--8
//c) i | nternationalizatio | n--> i18n
//
//1
//1-- - 5----0
//d) l | ocalizatio | n--> l10n
//Assume you have a dictionary and given a word, find whether its abbreviation is unique in the dictionary.
//A word's abbreviation is unique if no other word from the dictionary has the same abbreviation.
//Example:
//Given dictionary = ["deer", "door", "cake", "card"]
//
//isUnique("dear") -> false
//isUnique("cart") -> true
//isUnique("cane") -> false
//isUnique("make") -> true

// Your ValidWordAbbr object will be instantiated and called as such:
// ValidWordAbbr vwa(dictionary);
// vwa.isUnique("hello");
// vwa.isUnique("anotherWord");

#include "Header.h";
class ValidWordAbbr {
    map<string, vector<string>> map;
public:
    ValidWordAbbr(vector<string> &dictionary) {
        map.clear();
        for (size_t i = 0; i < dictionary.size(); i++) {
            string s = dictionary[i];
            string abbr = buildAbbr(s);
            // abbr is available now
            if (map.find(abbr) == map.end()) {
                vector<string> vs;
                vs.push_back(s);
                map[abbr] = vs;
            }
            else {
                map[abbr].push_back(s);
            }
        }
    }

    string buildAbbr(string s) {
        string abbr;
        if (s.size() <= 2) {
            abbr = s;
        }
        else {
            int len = s.size() - 2;
            abbr.push_back(s[0]);
            abbr.append(to_string(len));
            abbr.push_back(s[s.size() - 1]);
        }
        return abbr;
    }
    bool isUnique(string word) {
        string abbr = buildAbbr(word);
        if (map.find(abbr) == map.end()) {
            return true;
        }
        else if (map[abbr].size() == 1 && map[abbr][0] == word) {
            return true;
        }
        else {
            return false;
        }
    }
};