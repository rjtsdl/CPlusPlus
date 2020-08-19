//
//  a741CherryPickup.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/19/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int N = grid.size();
        vector<vector<int>> dp (N, vector<int>(N, INT_MIN));
        dp[0][0] = grid[0][0];

        for (int t = 1; t <= 2*N - 2; ++t) {
            vector<vector<int>> dp2 (N, vector<int>(N, INT_MIN));

            for (int i = max(0, t-(N-1)); i <= min(N-1, t); ++i) {
                for (int j = max(0, t-(N-1)); j <= min(N-1, t); ++j) {
                    if (grid[i][t-i] == -1 || grid[j][t-j] == -1) continue;
                    int val = grid[i][t-i];
                    if (i != j) val += grid[j][t-j];
                    for (int pi = i-1; pi <= i; ++pi)
                        for (int pj = j-1; pj <= j; ++pj)
                            if (pi >= 0 && pj >= 0)
                                dp2[i][j] = max(dp2[i][j], dp[pi][pj] + val);
                }
            }
            dp = dp2;
        }
        return max(0, dp[N-1][N-1]);
    }
};
