//
//  a1120MaximumAverageSubtree.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 9/23/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    double res;
    pair<int, int> solve(TreeNode *root) {
        /*
            returns pair <sum, number of nodes>
            in a subtree
            to the parent
            
            average is calculated at parent using
            number of nodes in left and right sub tree
            and sum of nodes in left and right sub tree
            
            avg is calculated at each node
            and hence updated to the result (to get max avg)
        */
        if(root == NULL)
            return {0, 0};
        auto [sum_left, num_left] = solve(root->left);
        auto [sum_right, num_right] = solve(root->right);
        int sum = root->val + sum_left + sum_right;
        int N = 1 + num_left + num_right;
        double avg = (double)sum / (double)(N);
        res = max(res, avg);
        return {sum, N};
    }
    double maximumAverageSubtree(TreeNode* root) {
        res = 0.0;
        solve(root);
        return res;
    }
};
