//All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG".When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.
//Write a function to find all the 10 - letter - long sequences(substrings) that occur more than once in a DNA molecule.
//For example,
//Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",
//
//Return :
//    ["AAAAACCCCC", "CCCCCAAAAA"].

#include "Header.h";
vector<string> Solution::findRepeatedDnaSequences(string s) {
    //map<char, int> dict;
    //dict['A'] = 0;
    //dict['C'] = 1;
    //dict['G'] = 2;
    //dict['T'] = 3;

    //vector<string> result;
    //if (s.length()<10) {
    //    return result;
    //}

    //int hash = 0;
    //set<int> first;
    //set<int> twice;
    //for (int i = 0; i < s.length(); i++) {
    //    if (i < 9) {
    //        hash = (hash << 2) + dict[s[i]];
    //    }
    //    else {
    //        hash = (hash << 2) + dict[s[i]];
    //        hash = hash&((1 << 20) - 1); //get i-9 to i
    //        if (first.find(hash) != first.end() && twice.find(hash) == twice.end()) {//found the second time.
    //            twice.insert(hash);
    //            result.push_back(s.substr(i-9,10));
    //        }
    //        if (first.find(hash) == first.end()) {// found the first time
    //            first.insert(hash);
    //        }
    //    }
    //}
    //return result;


    //use three bits to represent each A G C T. A 10-letter sequence is 3FFFFFFF long.
    map<int, int> m;
    vector<string> r;
    int t = 0, i = 0, ss = s.size();
    while (i < ss)
        if (m[t = (t << 3 | s[i++] & 7) & 0x3FFFFFFF]++ == 1)
            r.push_back(s.substr(i - 10, 10));
    return r;
}