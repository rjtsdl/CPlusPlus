//
//  a865SmallestSubtreewithalltheDeepestNodes.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 10/18/20.
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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        TreeNode* lca = nullptr;
        dfs(root, lca);
        return lca;
        
    }
    
    int dfs(TreeNode* root, TreeNode*& lca) {
        // return the depth
        if (root == nullptr) return 0;
        
        TreeNode* llca =  nullptr;
        TreeNode* rlca = nullptr;
        int l = dfs(root->left, llca);
        int r = dfs(root->right, rlca);
        
        if (l == r) {
            lca = root;
        } else if (l > r) {
            lca = llca;
        } else {
            lca = rlca;
        }
        return max(l, r)+1;
    }
};
