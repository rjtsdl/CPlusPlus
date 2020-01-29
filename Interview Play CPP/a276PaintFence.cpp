//
//  a276PaintFence.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 1/29/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    int numWays(int n, int k) {
        if (n == 0 || k ==0) {
            return 0;
        }
        // We can reduce the vector to just keep 2 variable to limit it to const space
        vector<int> nosame(n, 0);
        vector<int> adj(n, 0);
        nosame[0] = k;
        adj[0] = 0;
        for(int i =1; i < n; ++i) {
            nosame[i] = (adj[i-1] + nosame[i-1]) * (k-1);
            adj[i] = nosame[i-1];
        }
        
        return adj[n-1] + nosame[n-1];
        
    }
};
