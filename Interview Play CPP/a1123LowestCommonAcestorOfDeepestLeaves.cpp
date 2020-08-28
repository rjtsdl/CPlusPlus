//
//  a1123LowestCommonAcestorOfDeepestLeaves.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/28/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <stack>

using namespace std;

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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
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
