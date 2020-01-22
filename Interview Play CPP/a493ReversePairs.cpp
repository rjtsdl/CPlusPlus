//
//  a493ReversePairs.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 1/21/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <iostream>
#include "libraries/bit.hpp"

using namespace std;

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        
        vector<int> nums_cp (nums.begin(), nums.end());
        sort(nums_cp.begin(), nums_cp.end());
        
        BIT* bit = new BIT(vector<int>(nums_cp.size()));
        
        int count = 0;
        
        for (int i =0; i < nums.size(); ++i) {
            long pvt = 2*(long)nums[i]+1;
            auto it = lower_bound(nums_cp.begin(), nums_cp.end(), pvt);
            
            int idx;
            if (it == nums_cp.end()) {
                idx = (int)nums_cp.size();
            } else {
                idx = (int)(it-nums_cp.begin());
            }
            
            count += bit->search(idx+1);
            cout << "count at " <<i << " : " << count << endl;
            
            
            pvt = nums[i];
            it = lower_bound(nums_cp.begin(), nums_cp.end(), pvt);
            if (it == nums_cp.end()) {
                idx = (int)nums_cp.size();
            } else {
                idx = (int)(it-nums_cp.begin());
            }
            bit->update(idx+1, 1);
            bit->print();
        }
        
        bit->print();
        
        return count;
        
    }
};

/*
int main()
{
    Solution sol;
    vector<int> test{1,3,2,3,1};
    int res = sol.reversePairs(test);
    cout << "reversePairs counts : " <<  res << endl;
}
 */
