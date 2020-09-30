//
//  a1427PerformStringShifts.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 9/29/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int sz = s.size(), p = 0; char str[sz + 1]; str[sz] = 0;
        /* track the first letter's position as we do the shift operations */
        for (auto s : shift) p = (p + (s[0] ? 1 : -1) * s[1]) % sz;
        if (p < 0) p += sz; /* if -ve, adjust it */
        /* construct a new string with first letter beginning at position p */
        for (int i = 0; i < sz; i++) str[p++ % sz] = s[i];
        return str;
    }
};
