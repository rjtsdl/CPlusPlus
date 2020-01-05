//
//  a360SortTransformedArray.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 1/4/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include "math.h"

using namespace std;

class Solution {
public:
    int cal(int x, int a, int b, int c) {
        return a*x*x+b*x+c;
    }
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        int n=nums.size(), i, j;
        if (!n) return {};
        if (!a && !b) return vector<int>(n, c);
        vector<int> ret;
        if ((!a && b>0) || (a>0 && double(-b)/2/a<=nums[0]) || (a<0 && double(-b)/2/a>=nums.back())) {
            for(auto x:nums) ret.push_back(cal(x, a, b, c));
        } else if ((!a && b<0) || (a>0 && double(-b)/2/a>=nums.back()) || (a<0 && double(-b)/2/a<=nums[0])) {
            for(i=n-1; i>=0; i--) ret.push_back(cal(nums[i], a, b, c));
        } else if (a>0) {
            auto it=upper_bound(nums.begin(), nums.end(), int(floor(double(-b)/2/a)));
            j=it-nums.begin(), i=j-1;
            double m=double(-b)/2/a;
            while(i>=0 && j<n) {
                double u=fabs(nums[i]-m), v=fabs(nums[j]-m);
                if (u<v) {
                    ret.push_back(cal(nums[i], a, b, c));
                    i--;
                } else {
                    ret.push_back(cal(nums[j], a, b, c));
                    j++;
                }
            }
            for(; i>=0; i--) ret.push_back(cal(nums[i], a, b, c));
            for(; j<n; j++) ret.push_back(cal(nums[j], a, b, c));
        } else {
            ret=sortTransformedArray(nums, -a, -b, -c);
            reverse(ret.begin(), ret.end());
            for(auto &v:ret) v=-v;
        }
        return ret;
    }
};
