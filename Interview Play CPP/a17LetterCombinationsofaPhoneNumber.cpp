//
//  a17LetterCombinationsofaPhoneNumber.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 11/12/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

class Solution {
    const vector<vector<string>> mp {
        {},
        {},
        {"a", "b", "c"},
        {"d", "e", "f"},
        {"g", "h", "i"},
        {"j", "k", "l"},
        {"m", "n", "o"},
        {"p", "q", "r", "s"},
        {"t", "u", "v"},
        {"w", "x", "y", "z"}
    };
public:
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return {};
        if (digits.size() == 1) return mp[digits[0]-'0'];
        
        vector<string> ret;
        vector<string> first = mp[digits[0]-'0'];
        
        vector<string> secondplus = letterCombinations(digits.substr(1));
        
        for (string ss: secondplus) {
            for (string f : first) {
                ret.push_back(f+ss);
            }
        }
        return ret;
    }
};
