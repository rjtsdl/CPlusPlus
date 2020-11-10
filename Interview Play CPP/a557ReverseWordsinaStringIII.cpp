//
//  a557ReverseWordsinaStringIII.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 11/10/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <string>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string res = "";
        string word = "";
        
        for (char c: s) {
            if (c != ' ') {
                word = c + word;
            } else {
                res += word;
                word = "";
                res += ' ';
            }
        }
        
        if (!word.empty()) {
            res += word;
        }
        
        return res;
        
    }
};
