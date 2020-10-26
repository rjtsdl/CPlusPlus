//
//  a469ConvexPolygon.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 10/26/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>

class Solution {
public:
    bool isConvex(vector<vector<int>>& points) {
        int prev_product = crossProduct(points[0], points[1], points[2]);
        bool positive = prev_product > 0;
        bool negative = prev_product < 0;
        
        for (int i = 2; i <= points.size(); ++i) {
            int current = i % points.size();
            int next = (i + 1) % points.size();
            
            auto product = crossProduct(points[i - 1], points[current], points[next]);
            
            if (!positive && !negative) {
                positive = product > 0;
                negative = product < 0;
                continue;
            }
            
            if (positive && product < 0)
                return false;

            if (negative && product > 0)
                return false;
        }
        
        return true;
        
    }
    
    int crossProduct(vector<int>& a, vector<int>& b, vector<int>& c) {
        vector<int> AB = { b[0] - a[0], b[1] - a[1] };
        vector<int> AC = { c[0] - a[0], c[1] - a[1] };
                
        return AB[0] * AC[1] - AB[1] * AC[0];
    }
};
