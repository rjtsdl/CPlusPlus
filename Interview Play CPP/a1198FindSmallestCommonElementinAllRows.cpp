//
//  a1198FindSmallestCommonElementinAllRows.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 9/25/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        int R{(int)mat.size()}, C{(int)mat[0].size()};
        std::vector<int> count(10001, 0);
        for(int j{0}; j < C; ++j)
            for(int i{0}; i < R; ++i)
                if(++count[mat[i][j]] == R) return mat[i][j];

        return -1;
    }
};
