//
//  a1473PaintHouseIII.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/26/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;


class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        // cur[ci][nj] = min(pre[ci][nj]+cost[k][ci], pre[cl][nj-1]+cost[k][ci])
        const int big = INT_MAX/2;
        vector<vector<int>> pre(n+1, vector<int>(target+1, big)), cur = pre;
        
        //first hourse
        for(int color=0; color<n; color++){
            const int c1 = houses[0]-1;
            if(c1 !=-1 && color != c1) continue;
            pre[color][1] = cost[0][color];
        }
       
        for(int k=1;k<m;k++){
            const int c1 = houses[k]-1;
            for(int color=0; color<n; color++){
                if(c1 !=-1 && color != c1) continue;
                for(int preColor = 0; preColor<n; preColor++){
                    for(int preTar = 1; preTar <= target; preTar++){
                        if(pre[preColor][preTar] >= big) continue;
                        if(preColor == color) cur[color][preTar] = min(cur[color][preTar], pre[color][preTar] + cost[k][color]);
                        else {
                            if(preTar < target)
                                cur[color][preTar+1] = min(cur[color][preTar+1], pre[preColor][preTar] + cost[k][color]);
                        }
                    }
                }
            }
            pre = move(cur);
            cur = vector<vector<int>>(n+1, vector<int>(target+1, big));
        }
        
        int res = big;
        for(const auto& v:pre) res = min(res, v[target]);
        if(res >= big) return -1;
        for(int i=0; i<m; i++)
            if(houses[i] != 0) res -= cost[i][houses[i]-1];
        return res;
    }
};
