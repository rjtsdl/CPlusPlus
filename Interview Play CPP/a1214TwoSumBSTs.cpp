//
//  a1214TwoSumBSTs.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 9/27/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>

class Solution {
public:
    bool dfs(TreeNode* r, int t, unordered_set<int>& s, int c) {
        if (!r) return false;
        if (!c) s.insert(r->val);
        return (c ? s.count(t - r->val) : 0) + dfs(r->left, t, s, c) + dfs(r->right, t, s, c);
    }
    bool twoSumBSTs(TreeNode* r1, TreeNode* r2, int t) {
        unordered_set<int> s;
        return dfs(r1, t, s, 0/* build set*/) + dfs(r2, t, s, 1/*check set*/);
    }
};
