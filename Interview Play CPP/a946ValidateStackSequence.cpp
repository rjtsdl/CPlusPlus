//
//  a946ValidateStackSequence.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/19/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped) {
        stack<int> si;
        int index = 0;
        for (int i = 0; i < pushed.size(); ++i) {
            si.push(pushed[i]);
            while(!si.empty() && si.top() == popped[index]) {
                index++;
                si.pop();
            }
        }
        return index == popped.size();
    }
};
