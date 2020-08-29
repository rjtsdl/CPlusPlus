//
//  a688KnightProbablityInChessboard.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/29/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    double knightProbability(int N, int K, int sr, int sc) {
        vector<vector<double>> dp(N, vector<double>(N, 0.0));
        vector<int> dr{2, 2, 1, 1, -1, -1, -2, -2};
        vector<int> dc{1, -1, 2, -2, 2, -2, 1, -1};

        dp[sr][sc] = 1;
        for (; K > 0; K--) {
            vector<vector<double>> dp2(N, vector<double>(N, 0.0));
            for (int r = 0; r < N; r++) {
                for (int c = 0; c < N; c++) {
                    for (int k = 0; k < 8; k++) {
                        int cr = r + dr[k];
                        int cc = c + dc[k];
                        if (0 <= cr && cr < N && 0 <= cc && cc < N) {
                            dp2[cr][cc] += dp[r][c] / 8.0;
                        }
                    }
                }
            }
            dp = dp2;
        }
        double ans = 0.0;
        for (auto row: dp) {
            for (double x: row) ans += x;
        }
        return ans;
    }
};
