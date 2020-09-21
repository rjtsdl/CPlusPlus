//
//  a656CoinPath.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 9/21/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> cheapestJump(vector<int>& a, int k) {
        int to[1000], cost[1100], dq[1001];
        int n = a.size(), hd = 0, tl = 0;
        cost[0] = -1, cost[n-1+k] = 0, dq[0] = n-1+k;

        for(int i=n-1; i>=0 && hd <= tl; i--){
            int ex = dq[hd];
            if(ex == i+k) hd++;
            if(a[i] == -1) continue;

            to[i] = ex, cost[i] = cost[ex]+a[i];
            while(hd <= tl && cost[i] <= cost[dq[tl]]) tl--;
            dq[++tl] = i;
        }

        if(cost[0] == -1) return {};

        vector<int> ret;
        for(int p=0; p != n-1+k; p = to[p]) ret.push_back(p+1);
        return ret;
    }
};
