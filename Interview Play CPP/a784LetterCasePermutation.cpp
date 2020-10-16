//
//  a784LetterCasePermutation.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 10/16/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> result;
        function<bool(char)> isAlphabet = [](char c){
            return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
        };
        function<void(string, int)> helper = [&](string s, int idx){
            result.push_back(s);
            for(int i = idx; i < s.size(); i++){
                if(!isAlphabet(s[i])) continue;
                s[i] = islower(s[i])? toupper(s[i]) : tolower(s[i]);
                helper(s, i + 1);
                s[i] = islower(s[i])? toupper(s[i]) : tolower(s[i]);
            }
        };
        helper(S, 0);
        return result;
    }
};
