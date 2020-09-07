//
//  a856ScoreofParentheses.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 9/7/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int scoreOfParentheses(string S) {
        int x = 1;
        int n = S.size();
        int result = 0;

        for(int i = 1; i < n; ++i){
            switch (S[i])
            {
            case ')':
                if(S[i-1] == '('){
                    result += (1 << (x-1));
                }
                --x;
                break;
            default:
                ++x;
                break;
            }
        }

        return result;
    }
};
