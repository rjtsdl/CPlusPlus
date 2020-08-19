//
//  a1428LeftmostColumnWithAtLeastAOne.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/19/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    class BinaryMatrix {
       public:
         int get(int row, int col);
         vector<int> dimensions();
    };
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        int leftMostColumn = INT_MAX;
        vector<int> d = binaryMatrix.dimensions();
        int r = d[0], c = d[1];
        
        for (int rr = 0; rr < r; rr++) {
            findLeftMostColumnOfRow(binaryMatrix, rr, c, leftMostColumn);
        }
        return leftMostColumn == INT_MAX ? -1: leftMostColumn;
    }
    
    void findLeftMostColumnOfRow(BinaryMatrix &binaryMatrix, int row, int numOfColumn, int& leftMostColumn) {
        if (leftMostColumn < numOfColumn && binaryMatrix.get(row, leftMostColumn) == 0) {
            return;
        }
        
        int l = 0, r = min(numOfColumn -1, leftMostColumn);
        while (l < r) {
            int mid = l + (r-l)/2;
            if (binaryMatrix.get(row, mid) == 0) {
                l = mid+1;
            } else {
                r = mid;
            }
        }
        
        if (l < numOfColumn && binaryMatrix.get(row, l) == 1 && l < leftMostColumn) {
            leftMostColumn = l;
        }
    }
};
