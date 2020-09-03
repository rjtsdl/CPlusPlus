//
//  a549BinaryTreeLongestConsecutiveSequenceII.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 9/2/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

/**
 * Definition for a binary tree node.
 *
 */
class Solution {
public:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };
    int maxval;
    int longestConsecutive(TreeNode* root) {
        longestPath(root);
        return maxval;
    }
    
    vector<int> longestPath(TreeNode* root) {
        if (root == nullptr)
            return {0,0};
        int inr = 1, dcr = 1;
        if (root->left != nullptr) {
            auto l = longestPath(root->left);
            if (root->val == root->left->val + 1)
                dcr = l[1] + 1;
            else if (root->val == root->left->val - 1)
                inr = l[0] + 1;
        }
        if (root->right != nullptr) {
            auto r = longestPath(root->right);
            if (root->val == root->right->val + 1)
                dcr = max(dcr, r[1] + 1);
            else if (root->val == root->right->val - 1)
                inr = max(inr, r[0] + 1);
        }
        maxval = max(maxval, dcr + inr - 1);
        return {inr, dcr};
    }
    
};
