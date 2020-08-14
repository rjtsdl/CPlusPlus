//
//  a986IntervalListIntersections.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/14/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        int a = 0;
        int b = 0;
        vector<vector<int>> res;
        while (a < A.size() && b < B.size()) {
            if (A[a][1] < B[b][0]) {
                a++;
            } else if (A[a][0] > B[b][1]) {
                b++;
            } else {
                res.push_back({
                    max(A[a][0], B[b][0]),
                    min(A[a][1], B[b][1])
                });
                
                if (A[a][1] == res.back()[1]) {
                    a++;
                }
                
                if (B[b][1] == res.back()[1]) {
                    b++;
                }
            }
        }
        
        return res;
        
    }
};
