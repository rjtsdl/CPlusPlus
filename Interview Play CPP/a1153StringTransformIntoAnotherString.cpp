//
//  a1153StringTransformIntoAnotherString.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/26/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool canConvert(string str1, string str2) {
        unordered_set<char> s1(str1.begin(), str1.end()), s2(str2.begin(), str2.end());
        unordered_map<char, char> m3;
        int m = str1.length();
        for (int i = 0; i < m; i ++) {
            if (m3.count(str1[i]) && m3[str1[i]] != str2[i]) return false;
            m3[str1[i]] = str2[i];
        }
        if (s1.size() == 26 && s2.size() == 26 && str1 != str2) return false;
        return true;
    }
};
