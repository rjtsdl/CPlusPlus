//
//  a547FriendCircles.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 11/10/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    
    int find(vector<int>& p, int a) {
        if (p[a] != a) p[a] = find(p, p[a]);
        return p[a];
    }
    
    void unio(vector<int>& p, int a, int b) {
        int pa = find(p, a);
        int pb = find(p, b);
        if (pa != pb) {
            p[pa] = pb;
        }
    }
    
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        vector<int> p(n);
        for (int i =0; i < n; i++) p[i] = i;
        
        for (int i = 0; i<n; i++) {
            for (int j = i+1; j< n; j++) {
                if (M[i][j]) unio(p, i, j);
            }
        }
        
        set<int> pset;
        for (int i =0; i <n; i++) {
            pset.insert(find(p, i));
        }
        
        return pset.size();
        
    }
};
