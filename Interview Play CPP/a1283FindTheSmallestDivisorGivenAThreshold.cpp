//
//  a1283FindTheSmallestDivisorGivenAThreshold.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/16/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include "math.h"

using namespace std;

class Solution {
public:
    bool can(long x , vector<int> & nums, int threshold){
        long cnt = 0;
        for(int i=0;i<(int) nums.size(); i++){
            cnt += ceil((1.0*nums[i])/x);
        }
        
        return cnt<=threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        long l = 0;
        long r = 1e6;
        long ans = 0;
        
        while(l+1<r){
            long mid = l + (r-l)/2;
            
            if(can(mid , nums, threshold)){
                r = mid;
                ans = mid;
            }
            
            else
            {
                l = mid;
            }
        }
        return ans;
    }
};
