//
//  SearchinRotatedSortedArrayII.cpp
//  Interview Play CPP
//
//  Created by Jingtao on 5/12/16.
//  Copyright © 2016 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
using namespace std;

class Solution {
public:
    
    bool search(vector<int>& nums, int target)
    {
        int l =0, r = nums.size();
        
        while (l < r) {
            int m = l + (r-l)/2;
            if (nums[m] == target) return true;
            if (nums[m] == nums[l]) {l++; continue;}
            bool isLeft = (nums[m] > nums[l]);
            if (isLeft && target >= nums[l] && target < nums[m]) {
                r = m;
            } else if (!isLeft && (target < nums[m] || target >= nums[l])) {
                r = m;
            } else {
                l = m+1;
            }
        }
        return false;
    }
    
};
