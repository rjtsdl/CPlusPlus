//
//  a1314MatrixBlockSum.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 9/6/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        
        int r = mat.size();
        int c = mat[0].size();
        vector<vector<int>> res(r,vector<int>(c));
        
        int sum = 0;
        for(int i=0;i<r;i++)
        {
            sum = 0;
            for(int j=0;j<c;j++)
            {
                sum+= mat[i][j];
                if(i>0)mat[i][j] = mat[i-1][j] + sum;
                else mat[i][j] = sum;
            }
        }

        int lower_i;
        int lower_j;
        int upper_i;
        int upper_j;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                lower_i = max(0,i-K);
                upper_i = min(i+K,r-1);
                lower_j = max(0,j-K);
                upper_j = min(j+K,c-1);
                
                res[i][j] = mat[upper_i][upper_j] - ((lower_j==0)?0:mat[upper_i][lower_j-1]) - ((lower_i==0)?0:mat[lower_i-1][upper_j]) + ((lower_i==0 || lower_j==0)?0:mat[lower_i-1][lower_j-1]);
            }
        }

        return res;
    }
};
