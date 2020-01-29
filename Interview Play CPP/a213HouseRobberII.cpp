//
//  a213HouseRobberII.cpp
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
        
        if (nums.empty()) return 0;
        if (nums.size() <= 2) return *max_element(nums.begin(),nums.end());
        
        vector<int> p1(nums.begin(), prev(nums.end()));
        vector<int> p2(next(nums.begin()), nums.end());
        
        return max(robI(p1), robI(p2));
        
    }
    
    int robI(vector<int>& nums) {
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
