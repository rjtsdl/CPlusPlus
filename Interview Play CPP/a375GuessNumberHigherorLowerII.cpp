//
//  a375GuessNumberHigherorLowerII.cpp
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
    int getMoneyAmount(int n) {
        vector<vector<int>> dp (n+1, vector<int>(n+1));

        for (int len = 2; len <= n; len++) {
            for (int start = 1; start <= n - len + 1; start++) {
                int minres = INT_MAX;
                for (int piv = start + (len - 1) / 2; piv < start + len - 1; piv++) {
                    int res = piv + max(dp[start][piv - 1], dp[piv + 1][start + len - 1]);
                    minres = min(res, minres);
                }
                dp[start][start + len - 1] = minres;
            }

        }
        return dp[1][n];
    }
};
