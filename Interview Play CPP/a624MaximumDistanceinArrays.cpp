//
//  a624MaximumDistanceinArrays.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 1/4/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        
        priority_queue<pair<int, int>> minh;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> maxh;
        
        for (int i =0; i < arrays.size(); ++i) {
            maxh.push(make_pair(arrays[i].back(), i));
            minh.push(make_pair(arrays[i].front(), i));
            
            while(maxh.size() > 2) maxh.pop();
            while(minh.size() > 2) minh.pop();
        }
        
        auto min2 = minh.top(); minh.pop();
        auto min1 = minh.top();
        
        auto max2 = maxh.top(); maxh.pop();
        auto max1 = maxh.top();
        
        if (max1.second != min1.second) return max1.first - min1.first;
        return max(max1.first - min2.first, max2.first - min1.first);
        
    }
};
