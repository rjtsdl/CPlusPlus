//
//  SpiralMatrxII.cpp
//  Interview Play CPP
//
//  Created by Jingtao on 5/7/16.
//  Copyright © 2016 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix;
        for (int i =0 ; i<n; i++) {
            matrix.push_back(vector<int>(n));
        }
        int nextStartValue = 1;
        while (n > 0) {
            fillOnePerimeter(matrix, n, nextStartValue);
            n-=2;
        }
        return matrix;
    }
    
    void fillOnePerimeter(vector<vector<int>>& matrix, int n, int& nextStartValue)
    {
        if (n == 0) {
            return;
        }
        size_t len = matrix.size();
        int x = (int)(len - n)/2;
        int y = (int)(len - n)/2;
        if (n == 1) {
            matrix[x][y] = nextStartValue;
            ++nextStartValue;
            return;
        }
        // from left to right
        int rightMostValue = nextStartValue + n - 1;
        while (nextStartValue < rightMostValue) {
            matrix[x][y] = nextStartValue;
            ++nextStartValue;
            ++y;
        }
        // from up to down
        int downMostValue = nextStartValue + n - 1;
        while (nextStartValue < downMostValue) {
            matrix[x][y] = nextStartValue;
            ++nextStartValue;
            ++x;
        }
        // from right to left
        int leftMostValue = nextStartValue + n - 1;
        while (nextStartValue < leftMostValue) {
            matrix[x][y] = nextStartValue;
            ++nextStartValue;
            --y;
        }
        // from down to up
        int upMostValue = nextStartValue + n - 1;
        while (nextStartValue < upMostValue) {
            matrix[x][y] = nextStartValue;
            ++nextStartValue;
            --x;
        }
        return;
    }
};
