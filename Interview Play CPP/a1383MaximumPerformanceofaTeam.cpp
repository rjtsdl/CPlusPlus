//
//  a1383MaximumPerformanceofaTeam.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 9/6/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <queue>
#include <set>
#include <cmath>


using namespace std;

class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++) v.emplace_back(make_pair(efficiency[i], speed[i]));
        sort(v.begin(), v.end(), greater<pair<int,int>>());
        priority_queue<int, vector<int>, greater<int>> q;
        long long sumSpeed = 0, res = 0;
        for(auto [eff, speed] : v){
            q.push(speed);
            sumSpeed += speed;
            if(q.size() > k){sumSpeed -= q.top(); q.pop();}
            res = max(res, sumSpeed * eff);
        }
        return res % 1000000007;
    }
};
