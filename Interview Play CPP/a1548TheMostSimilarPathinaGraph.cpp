//
//  a1548TheMostSimilarPathinaGraph.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 9/30/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <string>

using namespace std;


class Solution {
public:
    vector<int> mostSimilar(int n, vector<vector<int>>& roads, vector<string>& names, vector<string>& targetPath) {
        int len = targetPath.size();
        vector<vector<int>> g(n, vector<int>()); // garph
        vector<vector<int>> dp(len, vector<int>(n, INT_MAX)); // dp[len][idx] min editDistance path of length len ending at node indexed idx
        vector<vector<int>> p(len, vector<int>(n, -1));

        for (auto &ed: roads) {
            int u = ed.front(); int v = ed.back();
            g[u].push_back(v); g[v].push_back(u);
        }
        
        for (int l =0; l < len; l++) {
            for (int j = 0; j<n; j++) {
                int cdist = (names[j] != targetPath[l] ?1:0);
                if (l==0) dp[l][j] = cdist;
                else {
                    int idx = -1; int minv = INT_MAX;
                    for(int i: g[j]) if (dp[l-1][i] < minv) minv = dp[l-1][i], idx=i;
                    p[l][j] = idx; dp[l][j] = cdist + minv;
                }
            }
        }
        
        
        int minv = *min_element(dp[len-1].begin(), dp[len-1].end());
        int u = -1; for (int i = 0; i<n; i++) if (dp[len-1][i] == minv) { u=i; break;}
        int cl = len-1;
        vector<int> ret;
        while (u != -1) {
            ret.push_back(u);
            u = p[cl][u]; cl--;
        }

        reverse(ret.begin(), ret.end());
        return ret;
    }
};
