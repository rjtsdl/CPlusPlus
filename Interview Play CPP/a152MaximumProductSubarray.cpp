//
//  a152MaximumProductSubarray.cpp
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
    int maxProduct(vector<int>& nums) {
        int maxi = INT_MIN;    // global max
        int maxloc = 1, minloc = 1;     // max or min end here
        for (int num : nums) {          // negative could cause maxloc and minloc swap
            int prod1 = maxloc * num, prod2 = minloc * num;
            maxloc = max(num, max(prod1, prod2));
            minloc = min(num, min(prod1, prod2));
            maxi = max(maxi, maxloc);
        }
        return maxi;
    }
};
