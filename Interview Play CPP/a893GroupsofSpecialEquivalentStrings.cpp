//
//  a893GroupsofSpecialEquivalentStrings.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 10/23/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <string>
#include <set>

using namespace std;

class Solution {
public:
    int numSpecialEquivGroups(vector<string>& A) {
        set<vector<int>> seen;
        vector<int> count(52, 0);
        for (string S: A) {
            fill(count.begin(), count.end(), 0);
            for (int i = 0; i < S.length(); ++i)
                count[S[i] - 'a' + 26 * (i % 2)]++;
            seen.insert(count);
        }
        return seen.size();
    }
};
