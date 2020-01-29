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
        int size = nums.size();
        vector<int> leftProduct(size, 1);
        vector<int> rightProduct(size, 1);
        for(int i = 1; i< size; i++)
        {
            leftProduct[i] = leftProduct[i-1] * nums[i-1];
        }
        for (int i = size-2; i>=0; i--)
        {
            rightProduct[i] = rightProduct[i+1] * nums[i+1];
        }
        
        vector<int> ret(size);
        
        for(int i = 0; i< size; i++)
        {
            ret[i] = leftProduct[i] * rightProduct[i];
        }
        
        return ret;
        
    }
};
