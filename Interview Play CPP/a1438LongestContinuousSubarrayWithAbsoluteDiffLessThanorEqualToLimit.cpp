//
//  a1438LongestContinuousSubarrayWithAbsoluteDiffLessThanorEqualToLimit.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/18/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& a, int limit) {
        map<int, int>m;
        int n = a.size();
        if (n <=1) {
            return n;
        }
        int i = 0, j = 0;
        int maxlen = 0;
        while(i<n and j < n) {
            if (m.find(a[i]) == m.end())
                m[a[i]]++;
            
            int maxel = m.rbegin()->first;
            
            int minel = m.begin()->first;
            
            if (abs(maxel - minel) <= limit) {
                
                maxlen = max(maxlen, abs(i-j)+1);
                i++;
            }
            else {
                m.erase(a[j]);
                int x = a[j];
                while(a[j] == x) {
                    j++;
                }
            }
        }
        return maxlen;
    }
};
