//
//  a1101TheEarliestMomentWhenEveryoneBecomeFriends.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 9/23/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    /* Find the subset a vertex belongs to */
    int find(vector<int> &s, int x) {
        if (s[x] == -1) return x;   /* parent is itself */
        int r = find(s, s[x]);
        s[x] = r;                   /* path compression */
        return r;
    }
    
    /* Unionize two subsets */
    void _union(vector<int> &s, int x, int y, int& cnt) {
        int xp = find(s, x);
        int yp = find(s, y);
        if (xp != yp) { s[yp] = xp; cnt++; }
    }
    
    int earliestAcq(vector<vector<int>>& logs, int N) {
        vector<int> s(N, -1); int cnt = 0;
        sort(logs.begin(), logs.end());
        for (auto a : logs) {
            _union(s, a[1], a[2], cnt);     /* increase the set */
            if (cnt == N - 1) return a[0];  /* time when they all became friends
                                             * i.e all elements in s[] are set except one which will stay -1
                                             */
        }
        return -1;
    }
};
