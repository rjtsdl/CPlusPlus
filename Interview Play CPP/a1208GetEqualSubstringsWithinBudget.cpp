//
//  a1208GetEqualSubstringsWithinBudget.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 1/22/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <vector>

using namespace std;


class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        vector<int> carr(s.size(), 0);
        
        for (int i=0; i < carr.size(); ++i) {
            carr[i] = abs(s[i] - t[i]);
        }
        
        // using two pointer
        
        int i =0, j=0;
        int rolling = 0;
        int len = 0;
        
        while(i<carr.size() && j < carr.size()) {
            if (j < i) j = i;
            
            if (rolling <= maxCost) {
                rolling += carr[j++];
            } else {
                rolling -= carr[i++];
            }
            
            if (rolling <= maxCost) {
                len = max(len, j-i);
            }
        }
        
        return len;
    }
};
