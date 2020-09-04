//
//  a312BurstBalloons.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 9/4/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        // reframe the problem
        int n = nums.size() + 2;
        vector<int> new_nums (n);

        for(int i = 0; i < nums.size(); i++){
            new_nums[i+1] = nums[i];
        }

        new_nums[0] = new_nums[n - 1] = 1;

        // dp will store the results of our calls
        vector<vector<int>> dp(n, vector<int>(n));

        // iterate over dp and incrementally build up to dp[0][n-1]
        for (int left = n-2; left > -1; left--)
            for (int right = left+2; right < n; right++) {
                for (int i = left + 1; i < right; ++i)
                    // same formula to get the best score from (left, right) as before
                    dp[left][right] = max(dp[left][right],
                    new_nums[left] * new_nums[i] * new_nums[right] + dp[left][i] + dp[i][right]);
            }

        return dp[0][n - 1];
    }
};
