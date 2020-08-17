//
//  a545BoundaryOfBinaryTree.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/17/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <unordered_set>

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
    
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) {
            return res;
        }
        
        res.push_back(root->val);
        dfs(root->left, true, false, res);
        dfs(root->right, false, true, res);
        
        return res;
    }
    
    void dfs(TreeNode* root, bool isLB, bool isRB, vector<int>& res) {
        if (root == nullptr) return;
        bool added = false;
        if (isLB or isLeaf(root)) {
            res.push_back(root->val);
            added = true;
        }
        
        dfs(root->left, isLB, isRB && root->right == nullptr, res);
        dfs(root->right, isLB && root->left == nullptr, isRB, res);
        
        if (isRB and !added) {
            res.push_back(root->val);
        }
    }
    
    bool isLeaf(TreeNode* root) {
        return root != nullptr && root->left == nullptr and root->right == nullptr;
    }
};
