//
//  UniquePaths.cpp
//  Interview Play CPP
//
//  Created by Jingtao on 5/8/16.
//  Copyright © 2016 Jingtao Ren. All rights reserved.
//

#include <stdio.h>

class Solution {
public:
    int uniquePaths(int m, int n) {
        int counts[m][n];
        
        counts[0][0] = 1;
        for (int i =0; i < m; ++i) {
            for (int j=0; j<n; ++j) {
                counts[i][j] = 1;
                if (i-1 >=0) {
                    counts[i][j] += counts[i-1][j];
                }
                if (j-1 >= 0) {
                    counts[i][j] += counts[i][j-1];
                }
                if (counts[i][j] > 1) {
                    counts[i][j] -= 1;
                }
            }
        }
        return counts[m-1][n-1];
    }
};
