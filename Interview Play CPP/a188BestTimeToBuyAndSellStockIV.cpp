//
//  a188BestTimeToBuyAndSellStockIV.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/18/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        
        if (2 * k > prices.size()) {
            int res = 0;
            for (int i = 1; i < prices.size(); i++) {
                res += max(0, prices[i] - prices[i - 1]);
            }
            return res;
        }
        
        vector<vector<int>> dp(k+1, vector<int>(2, 0));
        
        for (int i =0 ; i < dp.size(); ++i) dp[i][0] = INT_MAX;
        
        for (int p : prices) {
            for (int i =1; i < dp.size(); ++i) {
                dp[i][0] = min(dp[i][0], p - dp[i-1][1]);
                dp[i][1] = max(dp[i][1], p-dp[i][0]);
            }
        }
        
        return dp[k][1];
    }
};
