//
//  a776SplitBST.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 10/16/20.
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
    vector<TreeNode*> splitBST(TreeNode* root, int V) {
        TreeNode* leftRoot = nullptr;
        TreeNode* rightRoot = nullptr;
        TreeNode* left = nullptr;
        TreeNode* right = nullptr;
        
        TreeNode* cur = root;
        while (cur != nullptr) {
            if (cur->val <= V) {
                if (leftRoot == nullptr) {
                    leftRoot = cur;
                }
                if (left != nullptr) left->right = cur;
                left = cur;
                cur = cur->right;
                left->right = nullptr;
            } else {
                if (rightRoot == nullptr) {
                    rightRoot = cur;
                }
                
                if (right != nullptr) right->left = cur;
                right = cur;
                cur = cur->left;
                right->left = nullptr;
            }
        }
        
        return {leftRoot, rightRoot};
        
    }
    
    
};
