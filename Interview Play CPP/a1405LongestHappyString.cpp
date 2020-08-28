//
//  a1405LongestHappyString.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/28/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        
        vector<int> availability{a, b, c};
        vector<int> leftover{2, 2, 2};
        
        string ans = "";
        
        while (continueOn(availability, leftover)) {
            // Pick the most of availability
            int target = 0;
            int targetAva = -1;
            for (int i = 0; i < 3; ++i) {
                if (min(availability[i], leftover[i]) && availability[i] > targetAva) {
                    targetAva = availability[i];
                    target = i;
                }
            }
            
            ans += 'a'+target;
            
            for (int i = 0; i < 3; ++i) {
                if (i == target) {
                    availability[i]--;
                    leftover[i]--;
                } else {
                    leftover[i] = 2;
                }
            }
            
        }
        return ans;
    }
    
    bool continueOn(vector<int>& avail, vector<int>& leftover) {
        return min(avail[0], leftover[0]) || min(avail[1], leftover[1]) || min(avail[2], leftover[2]);
    }
};
