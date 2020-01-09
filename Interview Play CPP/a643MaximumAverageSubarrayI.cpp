//
//  a643MaximumAverageSubarrayI.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 1/9/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        vector<int> prefix(nums.size()+1, 0);

        for (int i = 0; i < nums.size(); i++)
            prefix[i + 1] = prefix[i] + nums[i];

        double max = ((double) prefix[k]) / ((double) k);
        for (int i = k; i < prefix.size(); i ++)
        {
            if (prefix[i] - prefix[i-k] >= max * k) {
                max = double(prefix[i] - prefix[i-k])/k;
            }
        }
        return max;
    }
};
