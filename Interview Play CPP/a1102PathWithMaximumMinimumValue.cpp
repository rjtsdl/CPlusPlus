//
//  a1102PathWithMaximumMinimumValue.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 9/23/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <queue>

using namespace std;

class Solution {
public:
    int maximumMinimumPath(vector<vector<int>>& A) {
        int n = A.size();
        int m = A[0].size();
        if (n==1 && m==1)
        {
            return A[0][0];
        }
        priority_queue<pair<int,pair<int,int>>>pq;
        pq.push({A[0][0],{0,0}});
        int a[] = {0,0,1,-1};
        int b[] = {1,-1,0,0};
        int ans;
        while(!pq.empty())
        {
            int val = pq.top().first;
            pair<int,int>coord = pq.top().second;
            pq.pop();
            for (int i=0;i<4;i++)
            {
                int r = coord.first + a[i];
                int c = coord.second + b[i];
                if (r<0 || r>=n || c<0 || c>=m)
                {
                    continue;
                }
                if (A[r][c] == -1)
                {
                    continue;
                }
                ans = min(val,A[r][c]);
                if (r==n-1 && c==m-1)
                {
                    return ans;
                }
                A[r][c] = -1;
                pq.push({ans,{r,c}});
            }
            
            
        }
        return ans;
    }
};
