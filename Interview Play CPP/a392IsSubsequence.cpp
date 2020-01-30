//
//  a392IsSubsequence.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 1/30/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <string>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int idt = 0;
        int ids = 0;
        
        while (idt < t.size() && ids < s.size()) {
            if (s[ids] == t[idt]) {
                ids++;
            }
            idt++;
        }
        
        return ids == s.size();
    }
};
