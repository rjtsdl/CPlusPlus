//
//  GenerateParentheses.cpp
//  Interview Play CPP
//
//  Created by rjtsdl on 11/18/15.
//  Copyright © 2015 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        
        vector<vector<string>> dp;
        dp.reserve(n);
        for (int i = 0; i <= n; i++) {
            dp.push_back(vector<string>{});
        }
        dp[0].push_back(string(""));
        dp[1].push_back(string("()"));
        vector<string> res;
        if (n < 1) {
            return  res;
        }
        if (n == 1) {
            return dp[1];
        }
        
        for (int i = 2; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                for (const auto& prefix : dp[j]) {
                    for (const auto& suffix: dp[i-j-1]) {
                        dp[i].push_back("(" + prefix + ")" + suffix);
                    }
                }
            }
        }
        
        return  dp[n];
    }
};

int main ()
{
    Solution sol;
    sol.generateParenthesis(1);
}
