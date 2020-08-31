//
//  a1423MaximumPointsYouCanObtainFromCards.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/31/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int maxScore(vector<int>& a, int k) {
        int n = (int)a.size();
        
        int sum = 0;
        for(auto &val: a) {
            sum += val;
        }
        
        int i, s=0;
        int ans = 0;
        
        // first window
        for(i=0; i<n-k; i++) {
            s += a[i];
        }
        // for first window
        ans = max(sum - s, ans);
        
        for(; i<n; i++) {
           // window sliding
            s -= a[i-(n-k)];
            s += a[i];
            ans = max(ans, sum-s);
        }
        
        return ans;
    }
};
