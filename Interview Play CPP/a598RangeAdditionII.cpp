//
//  a598RangeAdditionII.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 1/4/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        vector<int> hor(n, 0);
        vector<int> ver(m, 0);
        for(auto v: ops) {
            hor[0] += 1;
            if (v[1] < n) hor[v[1]] -=1;
            
            
            ver[0] += 1;
            if (v[0] < m) ver[v[0]] -=1;
            
        }
        
        for (int i =1; i < hor.size(); ++i) {
            hor[i] += hor[i-1];
        }
        
        for (int i =1; i < ver.size(); ++i) {
            ver[i] += ver[i-1];
        }
        
        
        int hor_max = *max_element(hor.begin(), hor.end());
        int ver_max = *max_element(ver.begin(), ver.end());
        
        int hor_count = (int)count(hor.begin(), hor.end(), hor_max);
        int ver_count = (int)count(ver.begin(), ver.end(), ver_max);
        return hor_count * ver_count;
        
    }
};
