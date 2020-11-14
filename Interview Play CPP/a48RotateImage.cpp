//
//  RotateImage.cpp
//  Interview Play CPP
//
//  Created by Jingtao on 2/8/16.
//  Copyright © 2016 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int len = (int)matrix.size();
        if (len == 0) {
            return;
        }
        if (len != matrix[0].size()) {
            return;
        }
        
        // Now we get a valid len;
        int width = (int)ceil(len * 0.5);
        int height = (int)floor(len * 0.5);
        
        int temp = 0;
        for (int i = 0; i < width; ++i) {
            for (int j = 0; j < height; ++j) {
                temp = matrix[j][i];
                matrix[j][i] = matrix[len-1-i][j];
                matrix[len -i -1][j] = matrix[len - j -1][len-i-1];
                matrix[len-j-1][len-i-1] = matrix[i][len-j-1];
                matrix[i][len-j-1] = temp;
            }
        }
        return;
    }
};
