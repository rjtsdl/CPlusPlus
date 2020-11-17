//
//  a240SearchA2DMatrixII.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 11/17/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) return false;
        int m = matrix.size();
        int n = matrix[0].size();
        int i = 0;
        int j = n-1;
        
        while (i >=0 && i < m && j >=0 && j <n) {
            if (target == matrix[i][j]) return true;
            if (matrix[i][j] < target) i++;
            else j--;
        }
        return false;
    }
};
