//
//  a151ReverseWordsinaString.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 11/15/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <string>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string res = "";
        string cur = "";
        
        for (char c: s) {
            if (c == ' ') {
                if (!cur.empty()) {
                    reverse(cur.begin(), cur.end());
                    res += cur + " ";
                    cur = "";
                }
            } else {
                cur += c;
            }
        }
        
        if (!cur.empty()) {
            reverse(cur.begin(), cur.end());
            res += cur;
        }
                          
        reverse(res.begin(), res.end());
        if (res[0] == ' ') return res.substr(1);
        return res;
    }
};
