//
//  a169MajorityElement.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 1/22/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        nth_element(nums.begin(), nums.begin() + nums.size()/2, nums.end());
        return *(nums.begin() + nums.size()/2);
        /*
         int count = 0;
         int candidate = INT_MAX;

         for (int num : nums) {
             if (count == 0) {
                 candidate = num;
             }
             count += (num == candidate) ? 1 : -1;
         }

         return candidate;
         */
    }
};
