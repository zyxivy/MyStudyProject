//Compare two version numbers version1 and version2.
//If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.
//    You may assume that the version strings are non - empty and contain only digits and the.character.
//    The.character does not represent a decimal point and is used to separate number sequences.
//    For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second - level revision of the second first - level revision.
//    Here is an example of version numbers ordering :
//0.1 < 1.1 < 1.2 < 13.37

#include "Header.h";
int Solution::compareVersion(string version1, string version2) {
    if (version1.length() == 0 && version2.length() == 0) {
        return 0;
    }
    if (version1.length() == 0 && version2.length() != 0) {
        return -1;
    }
    if (version1.length() != 0 && version2.length() == 0) {
        return 1;
    }   
    if (version1[0] == '.' && version2[0] == '.') {
        return 0;
    }
    if (version1[0] == '.' && version2[0] != '.') {
        return -1;
    }
    if (version1[0] != '.' && version2[0] == '.') {
        return 1;
    }
    int i1 = 0;
    int j1 = 0;
    while (i1 < version1.length() && j1 < version2.length()) {
        while (version1[i1] == '.') {
            i1++;
        }
        while (version2[j1] == '.') {
            j1++;
        }
        int i2 = i1;
        int j2 = j1;
        int ver1 = 0;
        int ver2 = 0;
        while (i2 < version1.length() && version1[i2] != '.') {
            i2++;
        }
        while (j2 < version2.length() && version2[j2] != '.') {
            j2++;
        }    
        ver1 = stoi(version1.substr(i1, i2 - i1));
        ver2 = stoi(version2.substr(j1, j2 - j1));
        if (ver1 > ver2) {
            return 1;
        }
        if (ver1 < ver2) {
            return -1;
        }
        i1 = i2 + 1;
        j1 = j2 + 1;
    }

    if (i1 < version1.length()) {
        while (version1[i1] == '.') {
            i1++;
        }
        int i2 = i1;
        while (i1 < version1.length()) {
            while (i2 < version1.length() && version1[i2] != '.') {
                i2++;
            }
            int ver1 = 0;
            ver1 = stoi(version1.substr(i1, i2 - i1));
            if (ver1 > 0) {
                return 1;
            }
            i1 = i2 + 1;
        }
    }
    if (j1 < version2.length()) {
        while (version2[j1] == '.') {
            j1++;
        }
        int j2 = j1;
        while (j1 < version1.length()) {
            while (j2 < version1.length() && version1[j2] != '.') {
                j2++;
            }
            int ver2 = 0;
            ver2 = stoi(version1.substr(j1, j2 - j1));
            if (ver2 > 0) {
                return 1;
            }
            j1 = j2 + 1;
        }
    }
    return 0;
}