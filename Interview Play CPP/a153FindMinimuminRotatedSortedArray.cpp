//
//  a153FindMinimuminRotatedSortedArray.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 11/15/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l =0, r = nums.size()-1;
        while (l < r-1) {
            if (nums[l] < nums[r]) return nums[l];
            int m = l + (r-l)/2;
            if (nums[l] < nums[m]) {
                l = m+1;
            } else {
                r = m;
            }
        }
        return min(nums[l], nums[r]);
    }
};
