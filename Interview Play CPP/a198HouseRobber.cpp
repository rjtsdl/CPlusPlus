//
//  a198HouseRobber.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 1/29/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int prevMax = 0;
        int currMax = 0;
        for (int x : nums) {
            int temp = currMax;
            currMax = max(prevMax + x, currMax);
            prevMax = temp;
        }
        return currMax;
    }
};
