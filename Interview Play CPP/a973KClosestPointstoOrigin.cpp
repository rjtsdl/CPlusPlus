//
//  a973KClosestPointstoOrigin.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 1/20/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        std:nth_element(points.begin(),points.begin()+K-1, points.end(), [](const vector<int>& lhs, const vector<int>& rhs) {
            return lhs[0] * lhs[0] + lhs[1] * lhs[1] < rhs[0] * rhs[0] + rhs[1] * rhs[1];
        });
        
        auto it = points.begin()+K-1;
        int dis = (*it)[0] * (*it)[0] + (*it)[1] * (*it)[1];
        
        vector<vector<int>> ret;
        copy_if(points.begin(), points.end(), back_inserter(ret), [dis](vector<int>& lhs){
            return lhs[0] * lhs[0] + lhs[1] * lhs[1] <= dis;
        });
        
        return ret;
    }
};
