//
//  ThreeSum.cpp
//  Interview Play CPP
//
//  Created by rjtsdl on 11/1/15.
//  Copyright © 2015 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
using namespace std;

class Solution {
public:
    
    int advanceToNextDiff(vector<int>& nums, int cur)
    {
        int curNum = nums[cur];
        while ( cur < nums.size() && nums[cur] == curNum)
        {
            ++cur;
        }
        return cur;
    }
    
    int reverseToNextDiff(vector<int>& nums, int cur)
    {
        int curNum = nums[cur];
        while ( cur >= 0 && nums[cur] == curNum)
        {
            --cur;
        }
        return cur;
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        
        int a = 0;
        while ( a < nums.size())
        {
            int b = a + 1;
            int c = (int)nums.size() - 1;
            while (b < c) {
                if ( nums[a] + nums[b] + nums[c] == 0)
                {
                    ret.push_back(vector<int>({nums[a], nums[b], nums[c]}));
                    b = advanceToNextDiff(nums, b);
                }
                else if( nums[a] + nums[b] + nums[c] > 0 )
                {
                    c = reverseToNextDiff(nums, c);
                }
                else if( nums[a] + nums[b] + nums[c] < 0 )
                {
                    b = advanceToNextDiff(nums, b);
                }
                    
            }
            a = advanceToNextDiff(nums, a);
        
        }
        return ret;
        
    }
    
    // Four Sum
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        
        int a = 0;
        while ( a < nums.size())
        {
            int b = a + 1;
            while (b < nums.size()) {
            
                int c = b + 1;
                int d = (int)nums.size() - 1;
                while (c < d) {
                    if ( nums[a] + nums[b] + nums[c] + nums[d] == target)
                    {
                        ret.push_back(vector<int>({nums[a], nums[b], nums[c], nums[d]}));
                        c = advanceToNextDiff(nums, c);
                    }
                    else if( nums[a] + nums[b] + nums[c] + nums[d] > target )
                    {
                        d = reverseToNextDiff(nums, d);
                    }
                    else if( nums[a] + nums[b] + nums[c] + nums[d] < target )
                    {
                        c = advanceToNextDiff(nums, c);
                    }
                }
                b = advanceToNextDiff(nums, b);
            }
            a = advanceToNextDiff(nums, a);
            
        }
        return ret;
        
    }
    
    
    
};