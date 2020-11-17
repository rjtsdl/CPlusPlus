//
//  a238ProductofArrayExceptSelf.cpp
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
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ret(n, 1);
        for (int i =1; i < n; i ++) {
            ret[i] = ret[i-1] * nums[i-1];
        }
        
        int right = 1;
        for (int i = n-2; i>=0; i--) {
            ret[i] *= right * nums[i+1];
            right *= nums[i+1];
        }
        
        return ret;
    }
};
