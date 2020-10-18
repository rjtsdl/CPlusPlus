//
//  a848ShiftingLetters.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 10/17/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string shiftingLetters(string S, vector<int>& shifts) {
        for(int i = shifts.size() -2; i >= 0; i--) {
            shifts[i] += shifts[i+1]%26;
        }
        
        for (int i =0; i < shifts.size(); i ++) {
            S[i] = (((S[i]-'a') + shifts[i]%26)) % 26 +'a';
        }
        return S;
    }
};
