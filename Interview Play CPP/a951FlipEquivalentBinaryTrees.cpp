//
//  a951FlipEquivalentBinaryTrees.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 10/8/20.
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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr && root2 == nullptr) return true;
        if (root1 == nullptr || root2 == nullptr) return false;
        if (root1->val != root2->val) return false;
        
        bool one = flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right);
        
        if (one) return true;
        
        one = flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left);
        
        return one;
    }
};
