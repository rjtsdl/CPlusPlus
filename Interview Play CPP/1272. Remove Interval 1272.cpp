//
//  1272. Remove Interval 1272.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 9/29/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& to)
    {
        vector<vector<int>> result;

        for (auto i : intervals)
        {
            if (i[0] < to[0])
                result.push_back({ i[0], min(i[1], to[0]) });

            if (i[1] > to[1])
                result.push_back({ max(i[0], to[1]), i[1] });
        }

        return result;
    }
};
