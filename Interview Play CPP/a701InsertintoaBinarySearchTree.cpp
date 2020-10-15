//
//  a701InsertintoaBinarySearchTree.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 10/15/20.
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* r = insertIntoBST(nullptr, root, true, val);
        return root == nullptr ? r: root;
        
    }
    
    TreeNode* insertIntoBST(TreeNode* p, TreeNode* cur, bool isLeft, int val) {
        if (cur == nullptr) {
            TreeNode* n = new TreeNode(val);
            
            if (p != nullptr) {
                if (isLeft) p->left = n;
                else p->right = n;
            }
            return n;
        }
        
        if (cur->val < val) {
            return insertIntoBST(cur, cur->right, false, val);
        } else {
            return insertIntoBST(cur, cur->left, true, val);
        }
    }
};
