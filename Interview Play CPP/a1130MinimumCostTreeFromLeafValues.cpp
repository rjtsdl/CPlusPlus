//
//  a1130MinimumCostTreeFromLeafValues.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/18/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <iostream>
#include <numeric>

using namespace std;

class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int maximum = 0;
        
        vector<vector<pair<int, int>>> mem(arr.size(), vector<pair<int, int>>(arr.size(), {INT_MAX, 0}));
        return helper(arr, 0, arr.size(), maximum, mem) - accumulate(arr.begin(), arr.end(), 0);
        
    }
    
    int helper(vector<int>& arr, int start, int end, int& maximum, vector<vector<pair<int, int>>>& mem) {
        if (start >= end) {
            return 0;
        }
        
        if (mem[start][end-1].first != INT_MAX) {
            maximum = mem[start][end-1].second;
            return mem[start][end-1].first;
        }
        
        if (start +1 == end) {
            maximum = max(maximum, arr[start]);
            mem[start][end-1] = make_pair(min(mem[start][end-1].first, arr[start]), maximum);
            return arr[start];
        }
        
        int minSum = INT_MAX;
        
        for (int i = start; i < end-1; ++i) {
            int ls, lm=0, rs, rm=0;
            ls = helper(arr, start, i+1, lm, mem);
            rs = helper(arr, i+1, end, rm, mem);
            maximum = max(maximum, max(lm, rm));
            minSum = min(minSum, ls+rs + lm*rm);
            mem[start][end-1] = make_pair(min(mem[start][end-1].first, minSum), maximum);
        }
        
        return minSum;
    }
};
/*
int main() {
    Solution* sol = new Solution();
    vector<int> arr{6,2,4};
    sol->mctFromLeafValues(arr);
    
    return 0;
}
*/
