//
//  a215KthLargestElementinanArray.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 11/16/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        nth_element(nums.begin(), nums.begin()+k-1, nums.end(), greater<int>());
        return *(nums.begin()+k-1);
        
    }
};
