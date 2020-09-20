//
//  a487MaxConsecutiveOnesII.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 9/19/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int longest = 0;
        int curOnes = 0;
        int curOnesWithFlip = 0;
        
        for (int n : nums) {
            if (n == 1) {
                curOnes++;
                curOnesWithFlip++;
            } else {
                curOnesWithFlip = curOnes+1;
                curOnes = 0;
                
            }
            longest = max(longest, curOnes);
            longest = max(longest, curOnesWithFlip);
        }
        return longest;
        
    }
};
