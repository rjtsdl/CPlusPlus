//
//  a844BackspaceStringCompare.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/21/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <string>

using namespace std;

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        return constructStr(S) == constructStr(T);
    }
    
    string constructStr(string S) {
        string res = "";
        int bsCount = 0;
        for (int i = S.size()-1; i>=0 ; i--) {
            if (S[i] == '#') {
                bsCount++;
                continue;
            }
            
            if (bsCount >0) {
                bsCount--;
                continue;
            }
            
            res += S[i];
        }
        return res;
    }
};
